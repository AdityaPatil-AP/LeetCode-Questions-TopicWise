class SnapshotArray
{
public:
    // Brute Force - Was not memory effecient because we were storing the whole array after every snap.
    // Memory Effecient + Binary Search - We are storing the history of records for every change occured for every particular
    // index. For storing that we are saving in the following format : {snap_id, value} .

    // The we can apply binary search to find the latest change for the given index's value which is less than or equal to snap_id.

    //     int snap_id;
    //     vector<vector<pair<int, int>>> history_records;

    //     SnapshotArray(int length) {
    //         snap_id = 0;
    //         history_records.resize(length);
    //         for(int i = 0;i < length;i++){
    //             history_records[i].push_back(make_pair(0, 0));
    //         }
    //     }

    //     void set(int index, int val) {
    //         history_records[index].push_back(make_pair(snap_id, val));
    //     }

    //     int snap() {
    //         return snap_id++;
    //     }

    //     int get(int index, int snap_id) {
    //         auto it = upper_bound(history_records[index].begin(), history_records[index].end(), make_pair(snap_id, INT_MAX));
    //         return prev(it)->second;
    //     }

    // Using map.

    // key -> index
    // value -> changes made to the current index.
    // value -> {snap_id, changed_value}.

    map<int, map<int, int>> history_records;
    int snap_id = 0;

    SnapshotArray(int length)
    {
    }

    void set(int index, int val)
    {
        history_records[index][snap_id] = val;
    }

    int snap()
    {
        return snap_id++;
    }

    int get(int index, int snap_id)
    {
        auto it = history_records[index].upper_bound(snap_id);

        return (it == history_records[index].begin()) ? 0 : prev(it)->second;
    }
};
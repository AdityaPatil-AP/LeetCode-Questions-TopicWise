class Solution
{
public:
    void insertInterval(vector<vector<int>> &intervals, vector<int> newInterval)
    {
        bool isInserted = false; // indicates whether we have inserted the interval or not.

        for (int i = 0; i < intervals.size(); i++)
        {
            if (newInterval[0] < intervals[i][0])
            {
                intervals.insert(intervals.begin() + i, newInterval);
                isInserted = true;
                break;
            }
        }

        if (!isInserted)
        {
            intervals.push_back(newInterval);
        }
        return;
    }

    bool doesIntervalOverlap(vector<int> interval1, vector<int> interval2)
    {
        return (min(interval1[1], interval2[1]) - max(interval1[0], interval2[0])) >= 0;
    }

    vector<int> mergeInterval(vector<int> interval1, vector<int> interval2)
    {
        return {min(interval1[0], interval2[0]), max(interval1[1], interval2[1])};
    }

    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        // Find the correct position of the current interval.
        //         insertInterval(intervals, newInterval);
        //         vector<vector<int>> ans;

        //         for(int i = 0;i < intervals.size();i++){
        //             vector<int> currInterval = intervals[i];

        //             // Merge until the lists get exhausted or no overlap is found.
        //             while(i < intervals.size() && doesIntervalOverlap(currInterval, intervals[i])){
        //                 currInterval = mergeInterval(currInterval, intervals[i]);
        //                 i++;
        //             }

        //             // Decrement to ensure we don't skip the interval due to outer for-loop incrementing.
        //             i--;
        //             ans.push_back(currInterval);
        //         }

        // return ans;

        int n = intervals.size(), i = 0;
        vector<vector<int>> res;
        // case 1: no overlapping case before the merge intervals
        // compare ending point of intervals to starting point of newInterval
        while (i < n && intervals[i][1] < newInterval[0])
        {
            res.push_back(intervals[i]);
            i++;
        }
        // case 2: overlapping case and merging of intervals
        while (i < n && newInterval[1] >= intervals[i][0])
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.pushclass Solution{
            public :
                void insertInterval(vector<vector<int>> & intervals, vector<int> newInterval){
                    bool isInserted = false; // indicates whether we have inserted the interval or not.

        for (int i = 0; i < intervals.size(); i++)
        {
            if (newInterval[0] < intervals[i][0])
            {
                intervals.insert(intervals.begin() + i, newInterval);
                isInserted = true;
                break;
            }
        }

        if (!isInserted)
        {
            intervals.push_back(newInterval);
        }
        return;
    }

    bool doesIntervalOverlap(vector<int> interval1, vector<int> interval2)
    {
        return (min(interval1[1], interval2[1]) - max(interval1[0], interval2[0])) >= 0;
    }

    vector<int> mergeInterval(vector<int> interval1, vector<int> interval2)
    {
        return {min(interval1[0], interval2[0]), max(interval1[1], interval2[1])};
    }

    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        // Find the correct position of the current interval.
        //         insertInterval(intervals, newInterval);
        //         vector<vector<int>> ans;

        //         for(int i = 0;i < intervals.size();i++){
        //             vector<int> currInterval = intervals[i];

        //             // Merge until the lists get exhausted or no overlap is found.
        //             while(i < intervals.size() && doesIntervalOverlap(currInterval, intervals[i])){
        //                 currInterval = mergeInterval(currInterval, intervals[i]);
        //                 i++;
        //             }

        //             // Decrement to ensure we don't skip the interval due to outer for-loop incrementing.
        //             i--;
        //             ans.push_back(currInterval);
        //         }

        // return ans;

        int i = 0;
        int n = intervals.size();
        vector<vector<int>> res;

        // Till overlapping doesn't happen insert all the answers into the res array.
        while (i < n && intervals[i][1] < newInterval[0])
        {
            res.push_back(intervals[i]);
            i++;
        }

        // Now the overlapping intervals begin.
        while (i < n && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }

        res.push_back(newInterval);

        // After the overlapping intervals are finished push back the remaining intervals.
        while (i < n)
        {
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};
_back(newInterval);
// case 3: no overlapping of intervals after newinterval being merged
while (i < n)
{
    res.push_back(intervals[i]);
    i++;
}
        return res;
    }
};
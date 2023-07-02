class Solution {
public:
    // // O(n^2) solution is possible but giving some Wrong Answers
    // vector<int> findRightInterval(vector<vector<int>>& intervals) {
    //     map<vector<int>, int> ump;
    //     int n = intervals.size();
    //     for(int i = 0;i < n;i++){
    //         ump[intervals[i]] = i;
    //     }
    //     vector<int> indices(n, -1);
    //     sort(intervals.begin(), intervals.end());
    //     for(int i = 0;i < n-1;i++){
    //         for(int j = i + 1;j < n;j++){
    //             if(intervals[i][1] <= intervals[j][0]){
    //                 indices[ump[intervals[i]]] = ump[intervals[j]];
    //             }
    //         }
    //     }
    //     return indices;
    // }
    
    // Binary Search and Sort Function.
    // vector<int> findRightInterval(vector<vector<int>> &intervals){
    //     vector<int>ans;
    //     vector<pair<int, int>> val;
    //     int n = intervals.size();
    //     // Storing the unique starting positions and their starting indices.
    //     for(int i = 0;i < n;i++){
    //         val.push_back({intervals[i][0], i});
    //     }
    //     // Sorting them so that we can implement a Binary Search appraoch on them.
    //     sort(val.begin(), val.end());
    //     // for every intervals we try to find the right Interval.
    //     for(int i = 0;i < n;i++){
    //         int to_search = intervals[i][1];
    //         // initialise with -1 indicating we haven't found the right index
    //         int ans_val = -1;
    //         int low = 0, high = n - 1;
    //         while(low <= high){
    //             int mid = (low + high)/2;
    //             if(val[mid].first >= to_search){
    //                 ans_val = val[mid].second;
    //                 high = mid - 1;
    //             }
    //             else{
    //                 low = mid + 1;
    //             }
    //         }
    //         ans.push_back(ans_val);
    //     }
    //     return ans;
    // }
    
    // Using Unordered_map and lower_bound function
    vector<int> findRightInterval(vector<vector<int>>& intervals){
        // For storing the result indices
        vector<int> result;
        // map<int, int> - unique starting position corresponding to their starting positions in the original array.
        map<int, int> mp;
        int n = intervals.size();
        for(int i = 0;i < n;i++)
            mp[intervals[i][0]] = i;
        for(int i = 0;i < n;i++){
            auto it = mp.lower_bound(intervals[i][1]);
            if(it != mp.end()){
                result.push_back((*it).second);
            }
            else{
                result.push_back(-1);
            }
        }
        return result;
    }
};
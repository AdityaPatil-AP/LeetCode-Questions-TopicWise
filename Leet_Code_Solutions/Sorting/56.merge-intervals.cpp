class Solution {
public:
    // Using sort function
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1) return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int start = INT_MAX, end = INT_MIN;
        for(int i = 0;i < intervals.size();i++){
            if(intervals[i][0] > end){
                if(start != INT_MAX){
                    res.push_back({start, end});
                }
                start = intervals[i][0];
                end = intervals[i][1];
            }
            else{
                end = max(end, intervals[i][1]);
            }
        }
        if((res.size() >= 1 && (int)(res.back())[1] != end) || (res.size() == 0 && start != INT_MAX))
            res.push_back({start, end});
        return res;
        // res.push_back(intervals[0]);
        // for(int i = 1;i < intervals.size();i++){
        //     if(res.back()[1] >= intervals[i][0]) res.back()[1] = max(res.back()[1], intervals[i][1]);
        //     else res.push_back(intervals[i]);
        // }
        // return res;
    }
};
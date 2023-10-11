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

class Solution
{
public:
    static bool compareT(vector<int> &p1, vector<int> &p2)
    {
        if (p1[0] < p2[0])
        {
            return true;
        }
        if (p1[0] == p2[0])
        {
            if (p1[1] < p2[1])
            {
                return true;
            }
        }
        return false;
    }

    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        // Merge Intervals.
        // Merge all the overlapping intervals.
        // How to sort?
        // If I sort by the starting time.
        // We have to sort by the starting time because

        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end(), compareT);

        int start = intervals[0][0];
        int end = intervals[0][1];
        int n = intervals.size();

        for (int i = 1; i < n; i++)
        {
            if (end >= intervals[i][0])
            {
                end = max(intervals[i][1], end);
            }
            else
            {
                ans.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        ans.push_back({start, end});

        return ans;
    }
};
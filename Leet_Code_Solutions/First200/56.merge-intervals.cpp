class Solution
{
public:
    bool doesIntervalOverlap(vector<int> a, vector<int> b)
    {
        return (min(a[1], b[1]) - max(a[0], b[0])) >= 0;
    }

    // Using sort function.
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        //         vector<vector<int>> res; // will store all the non-overlapping intervals.
        //         int n = intervals.size();
        //         sort(intervals.begin(), intervals.end());
        //         for(int i = 0;i < n;i++){
        //             vector<int> currInterval = intervals[i];

        //             // Until the intervals exist and they are overlapping, we will merge them.
        //             while(i < n && doesIntervalOverlap(currInterval, intervals[i])){
        //                 currInterval[0] = min(currInterval[0], intervals[i][0]);
        //                 currInterval[1] = max(currInterval[1], intervals[i][1]);
        //                 i++;
        //             }

        //             // Decrementing because we checked for the last interval but it did not overlap therefore, we need to
        //             // check it the next time.
        //             res.push_back(currInterval);
        //             i--;
        //         }
        //         return res;

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        for (auto interval : intervals)
        {
            // if the list of merged intervals is empty or if the current
            // interval does not overlap with the previous, simply append it.
            if (merged.empty() || merged.back()[1] < interval[0])
            {
                merged.push_back(interval);
            }
            // otherwise, there is overlap, so we merge the current and previous
            // intervals.
            else
            {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        return merged;
    }
};
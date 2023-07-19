class Solution
{
public:
    static bool comp(vector<int> &i1, vector<int> &i2)
    {
        return i1[1] < i2[1];
    }

    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        // Sort by earliest ending time. As it would make space for more
        // intervals to involve in the answer.
        // If the ending time are equal take the one with the highest starting time.
        sort(intervals.begin(), intervals.end(), comp);

        int ans = 0;
        int n = intervals.size();
        int curr_ending = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            int x = intervals[i][0];
            int y = intervals[i][1];

            if (x >= curr_ending)
            {
                curr_ending = y;
            }
            else
            {
                ans++;
            }
        }

        return ans;

        // int i = 0;
        // int n = intervals.size();
        // while(i < n){
        //     int j = i;
        //     int start_time = intervals[j][0];
        //     int end_time = intervals[j][1];
        //     j++;
        //     while(j < n && end_time > intervals[j][0]){
        //         j++;
        //     }

        //     ans += (j - i - 1);
        //     i = j;
        // }

        // return ans;
    }
};
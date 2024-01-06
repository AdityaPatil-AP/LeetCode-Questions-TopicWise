class Solution
{
public:
    vector<int> dp;
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        // startTime -> {endTime, profit}.
        vector<pair<int, vector<int>>> intervals;

        int n = startTime.size();
        for (int i = 0; i < n; i++)
        {
            intervals.push_back({startTime[i], {endTime[i], profit[i]}});
        }

        sort(intervals.begin(), intervals.end());

        dp.resize(n + 1, -1);

        return f(0, intervals);
    }

    int f(int i, vector<pair<int, vector<int>>> &intervals)
    {
        if (i == intervals.size())
        {
            return 0;
        }

        if (dp[i] != -1)
        {
            return dp[i];
        }

        int j = binarySearch(i, intervals);
        int pick = (intervals[i].second)[1] + f(j, intervals);

        int notPick = f(i + 1, intervals);

        return dp[i] = max(pick, notPick);
    }

    int binarySearch(int i, vector<pair<int, vector<int>>> &intervals)
    {
        int n = intervals.size();
        int endTime = intervals[i].second[0];

        int ans = n;
        int left = i + 1, right = n - 1;
        while (left <= right)
        {
            int mid = (left + (right - left) / 2);

            if (intervals[mid].first >= endTime)
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};
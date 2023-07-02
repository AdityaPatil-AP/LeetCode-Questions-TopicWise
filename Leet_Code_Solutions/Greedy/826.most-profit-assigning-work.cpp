class Solution
{
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {
        // n - number of jobs.
        int n = difficulty.size();

        // m - number of workers.
        int m = worker.size();

        // every worker will try to maximise the profit amongst the job he can do.
        // difficulty to profit.
        vector<pair<int, int>> dp;
        for (int i = 0; i < n; i++)
        {
            dp.push_back({difficulty[i], profit[i]});
        }

        sort(dp.begin(), dp.end());
        sort(worker.begin(), worker.end());

        // Here the best variable will store the maximum profit based on skill.
        int ans = 0, best = 0, i = 0;
        for (auto skill : worker)
        {
            while (i < n && skill >= dp[i].first)
            {
                best = max(best, dp[i++].second);
            }
            ans += best;
        }
        return ans;
    }
};
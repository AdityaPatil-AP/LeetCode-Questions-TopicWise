class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        // Let's store the minCost to reach at the ith step in dp array.
        int n = cost.size();
        vector<int> dp(n + 1, 0);

        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i < n; i++)
        {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }

        return min(dp[n - 1], dp[n - 2]);
    }
};
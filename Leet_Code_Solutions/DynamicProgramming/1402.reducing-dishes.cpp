class Solution
{
public:
    int maxSatisfaction(vector<int> &satisfaction)
    {
        int n = satisfaction.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1e9));
        sort(satisfaction.begin(), satisfaction.end());

        for (int i = 0; i <= n; i++)
        {
            for (int t = 0; t <= n; t++)
            {
                if (t == 0)
                {
                    dp[i][t] = 0;
                }
                else if (i == 0 && t > i)
                {
                    dp[i][t] = -1e9;
                }
                else
                {
                    // two cases not picking up the dish, or picking up the dish.
                    dp[i][t] = max(dp[i - 1][t], satisfaction[i - 1] * t + dp[i - 1][t - 1]);
                }
            }
        }

        int ans = -1e9;
        for (int i = 0; i <= n; i++)
        {

            ans = max(ans, dp[n][i]);
        }

        return ans;
    }
};
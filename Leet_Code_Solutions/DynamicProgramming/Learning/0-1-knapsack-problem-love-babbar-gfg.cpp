class Solution
{
public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {
        // Your code here
        //   int ans = helper(0, W, wt, val, n);

        //   return ans;

        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

        // i -> i - 1.

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= W; j++)
            {
                int pick = 0, not_pick = 0;

                if (j - wt[i - 1] >= 0)
                {
                    pick = dp[i - 1][j - wt[i - 1]] + val[i - 1];
                }

                not_pick = dp[i - 1][j];

                dp[i][j] = max(pick, not_pick);
            }
        }

        return dp[n][W];
    }
};
class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        vector<vector<int>> dp(amount + 1, vector<int>(coins.size() + 1, 0));

        int totalCoins = coins.size();

        for (int i = 0; i < totalCoins; i++)
        {
            dp[0][i] = 1;
        }

        sort(coins.begin(), coins.end());

        for (int j = 0; j < totalCoins; j++)
        {
            for (int i = 1; i <= amount; i++)
            {
                if (i - coins[j] >= 0)
                {
                    dp[i][j] = dp[i - coins[j]][j];
                    if (j - 1 >= 0)
                    {
                        dp[i][j] += dp[i][j - 1];
                    }
                }
                else
                {
                    if (j - 1 >= 0)
                        dp[i][j] = dp[i][j - 1];
                }
            }
        }

        return dp[amount][totalCoins - 1];
    }
};
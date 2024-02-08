class Solution
{
public:
    int numSquares(int n)
    {
        // int dp[n + 1];

        // memset(dp, -1, sizeof(dp));

        // return solve(dp, n);

        // bottom up approach.

        vector<int> dp(n + 1, 1e9);

        dp[0] = 0;

        for (int i = 1; i <= n; i++)
        {

            for (int j = 1; j * j <= i; j++)
            {
                dp[i] = min(dp[i], 1 + dp[i - j * j]);
            }
        }

        return dp[n];
    }

    int solve(int dp[], int i)
    {
        if (i == 0)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int ans = 1e9;

        for (int j = 1; j * j <= i; j++)
        {
            int curr = j * j;
            ans = min(ans, 1 + solve(dp, i - curr));
        }

        return dp[i] = ans;
    }
};
class Solution
{
public:
    int kInversePairs(int n, int k)
    {
        int dp[1001][1001] = {1};
        const int mod = 1e9 + 7;
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                // // we take the minimum of both. Because for a size i array we have maximum
                // // (i - 1) inverse pairs possible.
                // for(int x = 0;x <= min(j, i - 1);x++){
                //     if(j - x >= 0)
                //         dp[i][j] = (dp[i][j] + dp[i - 1][j - x]) % mod;
                // }

                // Use Recurrence Relation we can optimise this loop to O(1) operation.
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % mod;

                dp[i][j] = (dp[i][j] + mod - (j - i >= 0 ? dp[i - 1][j - i] : 0)) % mod;
            }
        }

        return dp[n][k];
    }
};
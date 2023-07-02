class Solution
{
public:
    int numMusicPlaylists(int n, int goal, int k)
    {
        // Using Dynamic Programming + Combinatorics.
        int mod = 1e9 + 7;

        long long dp[goal + 1][n + 1];

        memset(dp, 0, sizeof(dp));

        dp[0][0] = 1;
        for (int i = 1; i <= goal; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                // playing this song for the first time.
                dp[i][j] += (dp[i - 1][j - 1] * (n - j + 1));
                // repeating a song.
                dp[i][j] += (dp[i - 1][j] * max(j - k, 0));

                dp[i][j] %= mod;
            }
        }

        return (int)dp[goal][n];
    }
};
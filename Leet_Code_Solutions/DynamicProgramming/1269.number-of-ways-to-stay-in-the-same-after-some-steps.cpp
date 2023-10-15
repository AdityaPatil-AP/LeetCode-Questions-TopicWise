class Solution
{
public:
    int numWays(int steps, int arrLen)
    {
        const int mod = 1e9 + 7;
        arrLen = min(steps, arrLen);
        // state -> depending factors : 1) Position(curr) 2) remaining steps.
        vector<vector<int>> dp(arrLen, vector<int>(steps + 1, 0));

        dp[0][0] = 1;

        // We have bound of [0, arrLen - 1].
        // dp[curr][remain] => Number of ways to end at 0 from curr when we have to make
        // remain number of steps.

        for (int remain = 1; remain <= steps; remain++)
        {
            for (int curr = arrLen - 1; curr >= 0; curr--)
            {
                int ans = dp[curr][remain - 1];

                if (curr - 1 >= 0)
                {
                    ans = (ans + dp[curr - 1][remain - 1]) % mod;
                }

                if (curr + 1 <= arrLen - 1)
                {
                    ans = (ans + dp[curr + 1][remain - 1]) % mod;
                }

                dp[curr][remain] = ans;
            }
        }

        return dp[0][steps];
    }
};
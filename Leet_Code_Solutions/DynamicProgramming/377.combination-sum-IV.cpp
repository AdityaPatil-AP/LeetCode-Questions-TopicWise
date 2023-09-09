class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        unsigned long long dp[target + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1ll;

        for (int i = 1; i <= target; i++)
        {
            for (int num : nums)
            {
                if (i - num >= 0)
                {
                    dp[i] += dp[i - num];
                }
            }
        }

        return dp[target];
    }
};
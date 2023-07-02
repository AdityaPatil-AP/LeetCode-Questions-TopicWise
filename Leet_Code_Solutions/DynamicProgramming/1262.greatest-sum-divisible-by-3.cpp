class Solution
{
public:
    // Recursion
    int solve(int index, vector<int> &nums, int currsum, vector<vector<int>> &dp)
    {
        if (index == nums.size())
        {
            // If we reach the end of the array and our currsum or k is divisible by 3 then
            // we can say that it is a subset divisible by 3 so we return 0.
            // or else the subset is not divisible by 3 so we return a huge negative integer value.
            if (currsum == 0)
            {
                return 0;
            }
            else
            {
                return -1e8;
            }
        }
        if (dp[index][currsum] != -1)
        {
            return dp[index][currsum];
        }
        // Let's say i choose it.
        int res1 = nums[index] + solve(index + 1, nums, (currsum + nums[index]) % 3, dp);
        // or i prefer to not choose it.
        int res2 = solve(index + 1, nums, currsum, dp);
        return dp[index][currsum] = max(res1, res2);
    }

    int maxSumDivThree(vector<int> &nums)
    {
        // Using Recursion.
        // parameters in check = index, nums, currsum
        // return solve(0, nums, 0);

        // The above solution will give TLE.
        // vector<vector<int>> dp(nums.size(),vector<int>(3, -1));
        // return solve(0, nums, 0, dp);

        // Using Tabulation. - Bottom - Up Approach.
        vector<vector<int>> dp(nums.size() + 1, vector<int>(3, INT_MIN));
        dp[0][0] = 0;
        int n = nums.size();
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= 2; j++)
            {
                int a = nums[i - 1] + dp[i - 1][(j + nums[i - 1]) % 3];
                int b = dp[i - 1][j];
                dp[i][j] = max(a, b);
            }
        }
        return dp[n][0];
    }
};
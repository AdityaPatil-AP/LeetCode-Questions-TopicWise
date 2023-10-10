class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        // Base case.
        // dp[currentIndex][increase] -> This indicates the longest
        // wiggle subsequence till currentIndex where now it is increasing
        // The same is for decreasing.
        // We have to send the maximum of 2.
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, 1));

        dp[0][0] = 1;
        dp[0][1] = 1;

        for (int i = 1; i < n; i++)
        {
            // We have to two options.
            // for the current number it may join and act as local maxima.
            // or it may act as a local minima.
            for (int j = i - 1; j >= 0; j--)
            {
                // Acting as a local maxima if possible
                if (nums[i] > nums[j])
                {
                    dp[i][1] = max(dp[i][1], dp[j][0] + 1);
                }

                // Acting as a local minima if possible.
                if (nums[j] > nums[i])
                {
                    dp[i][0] = max(dp[i][0], dp[j][1] + 1);
                }
            }
        }

        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};
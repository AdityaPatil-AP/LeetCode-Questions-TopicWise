class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        // So we are interested in choosing the largest number first.
        // We can at any point pick any element, or skip that element and choose the next one.

        // Here also we are going to use that idea.
        int n = nums.size();
        sort(nums.begin(), nums.end());

        // We will need to store the frequency of every element.
        unordered_map<int, int> mp;

        for (auto it : nums)
            mp[it]++;
        // Time Limit Exceeded.
        // So atleast we need to memoise it.
        // Check for the changing parameters.

        // 1)index. and that's it.
        // vector<int> dp(n, -1);
        // return solve(0, nums, mp, dp);

        // Space Optimised.
        vector<int> dp(n + 1, 0);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--)
        {

            int pick = nums[i] * mp[nums[i]];
            int not_pick = 0;
            if (i + mp[nums[i]] + mp[nums[i] + 1] <= n)
                pick += dp[i + mp[nums[i]] + mp[nums[i] + 1]];
            if (i + mp[nums[i]] <= n)
                not_pick = dp[i + mp[nums[i]]];

            dp[i] = max(pick, not_pick);
        }

        return dp[0];
    }

    int solve(int index, vector<int> &nums, unordered_map<int, int> &mp, vector<int> &dp)
    {
        if (index >= nums.size())
            return 0;

        // pick up the current element or else skip the current element.

        // At the end whichever gives us more points leads us to the answer.

        if (dp[index] != -1)
            return dp[index];

        int pick = nums[index] * mp[nums[index]];

        int new_index = index + mp[nums[index]] + mp[nums[index] + 1];

        pick += solve(new_index, nums, mp, dp);

        int not_pick = solve(index + mp[nums[index]], nums, mp, dp);

        return dp[index] = max(pick, not_pick);
    }
};
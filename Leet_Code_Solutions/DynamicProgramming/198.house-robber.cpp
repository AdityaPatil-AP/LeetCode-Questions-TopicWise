class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 0);

        // Edge Cases.
        //         if(n == 1) return nums[0];
        //         if(n == 2){
        //             return max(nums[0], nums[1]);
        //         }

        //         // Base Cases.
        //         dp[0] = nums[0];
        //         dp[1] = max(nums[0], nums[1]);
        //         // 1) You can either rob the current house and take the maximum loot
        //         // of the house before the previous house.
        //         // Or 2) you will skip the current house and take the loot of the previous house.
        //         // whichever gives you maximum is the answer.
        //         for(int i = 2;i < n;i++){
        //             dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        //         }

        //         return dp[n - 1];

        // Here we see that we are only concerned with the previous and the house before previous

        // so we are going to use prev, prev2 and the curr variable,
        int prev = nums[0];
        int prev2 = 0;
        for (int i = 1; i < n; i++)
        {
            int notRob = prev;
            int rob = prev2 + nums[i];

            int curr = max(rob, notRob);
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int ans = nums[0];
        int n = nums.size();
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = nums[0];

        for (int i = 2; i <= n; i++)
        {
            dp[i] = max(dp[i - 1], nums[i - 1] + dp[i - 2]);
        }

        return dp[n];
    }
};
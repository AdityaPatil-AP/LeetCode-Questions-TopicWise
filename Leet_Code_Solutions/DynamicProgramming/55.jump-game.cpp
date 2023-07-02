class Solution
{
public:
    // Recursion + Memoization...
    //     bool solve(int i, vector<int> &nums, vector<int> &dp){
    //         if(i == nums.size() - 1){
    //             return true;
    //         }
    //         if(dp[i] != -1) return dp[i];

    //         int reachable = i + nums[i];
    //         for(int k = i + 1;k <= reachable;k++){
    //             if(solve(k, nums, dp)){
    //                 return dp[i] = true;
    //             }
    //         }
    //         return dp[i] = false;
    //     }

    // Practice - Recursion Practice & memoisation.
    bool solve(int i, vector<int> &nums, vector<int> &dp)
    {
        if (i == (nums.size() - 1))
        {
            return true;
        }

        if (dp[i] != -1)
        {
            return dp[i];
        }

        int reachable = i + nums[i];
        for (int k = i + 1; k <= reachable; k++)
        {
            if (solve(k, nums, dp))
            {
                return dp[i] = true;
            }
        }
        return dp[i] = false;
    }

    bool canJump(vector<int> &nums)
    {
        // Wrong
        // bool ans = false;
        // int n = nums.size();
        // int nextJump = 0;
        // for(int i = 0;i < n - 1;){
        //     if(nums[nextJump] == 0){
        //         return false;
        //     }
        //     nextJump = i + 1;
        //     if((nums[i]) > (n - i - 1)){
        //         return true;
        //     }
        //     for(int j = i + 1;j <= i + nums[i] && j < n;j++){
        //         if(nums[j] >= nums[nextJump]){
        //             nextJump = j;
        //         }
        //     }
        //     i = nextJump;
        // }
        // return true;

        // Use the Reachability Concept
        //         int reachable = 0;
        //         int n = nums.size();

        //         for(int i = 0;i < n;i++){
        //             if(i > reachable) return false;
        //             // At every point we see if it's possible to update reachability.
        //             reachable = max(reachable, i + nums[i]);
        //         }
        //         return true;

        // 2) Recursive.. and then memoization.
        // vector<int> dp;
        // dp.assign(nums.size(), -1);
        // return solve(0, nums, dp);
        // Daily Question - Recursive.
        // vector<int> dp(nums.size(), -1);
        // return solve(0, nums, dp);

        // 3) Iterative.
        //         int n=nums.size();
        //         vector<int> dp(n,0);
        //         dp[0]=true;

        //         for(int i=1;i<n;i++){
        //              for(int j=i-1;j>=0;j--){
        //                  if(dp[j] && j+nums[j]>=i){
        //                      dp[i]=true;
        //                      break;
        //                  }
        //              }
        //         }
        //         return dp[n-1];

        // 3) Iterative Practice.
        // int n = nums.size();
        // vector<int> dp(n, 0);
        // dp[0] = 1;
        // for(int i = 1;i < n;i++){
        //     for(int j = i - 1;j >= 0;j--){
        //         if(dp[j] && (j + nums[j]) >= i){
        //             dp[i] = true;
        //             break;
        //         }
        //     }
        // }
        // return dp[n - 1];

        // 4) minjump required.
        int n = nums.size();
        int minjumps = 0;
        // to reach n - 1 from n - 2 we require min. 1 jump, if n - 2 have a value greater than or equal to 1, then we can reach
        // n - 1 from n - 2, now our ultimate goal is to reach n - 2, therefore the minimum jump required again becomes 0. because
        // we can reach n - 2 now.
        for (int i = n - 2; i >= 0; i--)
        {
            minjumps++;
            if (nums[i] >= minjumps)
            {
                minjumps = 0;
            }
        }
        return (!minjumps) ? true : false;
    }
};
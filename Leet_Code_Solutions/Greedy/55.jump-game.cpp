class Solution {
public:
    // Recursion + Memoization...
    bool solve(int i, vector<int> &nums, vector<int> &dp){
        if(i == nums.size() - 1){
            return true;
        }
        if(dp[i] != -1) return dp[i];
        
        int reachable = i + nums[i];
        for(int k = i + 1;k <= reachable;k++){
            if(solve(k, nums, dp)){
                return dp[i] = true;
            }
        }
        return dp[i] = false;
    }
    
    bool canJump(vector<int>& nums) {
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
        
        // 2) Recursive..
        vector<int> dp;
        dp.assign(nums.size(), -1);
        return solve(0, nums, dp);
    }
};
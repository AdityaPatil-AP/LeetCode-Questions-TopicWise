class Solution {
public:
    int solve(int n, vector<int> &dp){
        if(n == 0){
            return 0;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int min_steps = INT_MAX;
        for(int i = 1;i * i <= n;i++){
            min_steps = min(min_steps, 1 + solve(n - i * i, dp));
        }
        
        return dp[n] = min_steps;
    }
    
    int numSquares(int n) {
        // Recursion Based approach - divide and conquer. 
        // Top - Down Approach.
        // Memoisation.
        // vector<int> dp(n + 1, -1);
        // return solve(n, dp);
        
        
        // Using Bottom Up Approach.
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for(int sq = 1;sq <= n;sq++){
            // sq is the number we have to check.
            for(int i = 1;i * i <= sq;i++){
                dp[sq] = min(dp[sq], 1 + dp[sq - i*i]);
            }
        }
        
        return dp[n];
    }
};
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        // Recursive dp.
        // int n = s.size();
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return solve(0, n - 1, s, dp);
        
        // Iterative dp.
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int i = n - 1;i >= 0;i--){
            dp[i][i] = 1;
            for(int j = i + 1;j < n;j++){
                if(s[i] == s[j]){
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else{
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[0][n - 1];
    }
    
    int solve(int i, int j, string &s, vector<vector<int>> &dp){
        if(i == j){
            return 1;
        }
        if(i > j){
            return 0;
        }
        // Memoisation Step.
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(s[i] == s[j]){
            ans = 2 + solve(i + 1, j - 1,s, dp);
        }
        else{
            ans = max(solve(i + 1, j, s, dp), solve(i, j - 1, s, dp));
        }
        
        dp[i][j] = ans;
        return ans;
    }
};
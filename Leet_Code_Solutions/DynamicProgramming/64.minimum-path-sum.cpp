class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // Dp.
        // We are given a problem and we have to find the minimum path sum from top-left corner to 
        // the bottom right.
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int i = n - 1;i >= 0;i--){
            for(int j = m - 1;j >= 0;j--){
                if(i == (n - 1) && j == (m - 1)){
                    dp[i][j] = grid[i][j];
                }
                else{
                    // for going in bottom direction.
                    int path1 = INT_MAX;
                    // for going int right direction.
                    int path2 = INT_MAX;
                    // bottom
                    if(i + 1 < n){
                        path1 = min(path1, dp[i + 1][j]);
                    }
                    if(j + 1 < m){
                        path2 = min(path2, dp[i][j + 1]);
                    }
                    
                    dp[i][j] = grid[i][j] + min(path1, path2);
                }
            }
        }
        
        // final sub problem.
        return dp[0][0];
    }
};
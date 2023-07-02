class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        // In case of Rectangles it is much more intuitive if we solve it using 
        // Tabulation for dp on grids.
        // filling the base case.
        int m = mat.size();
        int n = mat[0].size();
        // Here the recurrence relation is hard to find.
        // dp[i][j] represents the number of squares that end at location (i, j). It may be of size 1 or 
        // size 2 or size 3 and so on.
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int ans = 0;
        for(int i = 0;i < m;i++){
            dp[i][0] = mat[i][0];
            ans += mat[i][0];
        }
        for(int j = 1;j < n;j++){
            dp[0][j] = mat[0][j];
            ans += mat[0][j];
        }
        for(int i = 1;i < m;i++){
            for(int j = 1;j < n;j++){
                if(mat[i][j] == 1){
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
                    ans += dp[i][j];
                }
                else dp[i][j] = 0;
            }
        }
        return ans;
    }
};
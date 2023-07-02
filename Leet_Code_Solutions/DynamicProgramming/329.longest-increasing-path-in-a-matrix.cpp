class Solution
{
public:
    int dp[201][201];

    int dfs(int i, int j, vector<vector<int>> &matrix)
    {
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int ans = 1;
        int n = matrix.size(), m = matrix[0].size();

        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};

        // Visit all the neighbouring cells.
        for (int k = 0; k < 4; k++)
        {
            int newi = i + dr[k];
            int newj = j + dc[k];

            // If the neighbouring cell has a larger value, then the maximum length of increasing path at this
            // cell can be extended to the next cell. If it is greater than the previously calculated path then
            // only the updation will take place.

            if (newi >= 0 && newj >= 0 && newi < n && newj < m && matrix[newi][newj] < matrix[i][j])
            {
                ans = max(ans, 1 + dfs(newi, newj, matrix));
            }
        }

        return dp[i][j] = ans;
    }

    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        // DFS + Memoisation.

        // key Concept -> length of increasing path ending at the current cell.
        int ans = INT_MIN;
        memset(dp, -1, sizeof(dp));
        int n = matrix.size(), m = matrix[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans = max(ans, dfs(i, j, matrix));
            }
        }

        return ans;

        //         // DP + sorting.
        //         // If any doubt in the concept. Go and see 2328 Solution.
        //         // We can sort the values.
        //         long long ans = INT_MIN;
        //         int n = matrix.size(), m = matrix[0].size();
        //         vector<pair<int, pair<int, int>>> arr;

        //         for(int i = 0;i < n;i++){
        //             for(int j = 0;j < m;j++){
        //                 arr.push_back({matrix[i][j], {i, j}});
        //             }
        //         }

        //         sort(arr.begin(), arr.end());

        //         vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1));

        //         for(auto currCell : arr){
        //             int i = currCell.second.first;
        //             int j = currCell.second.second;

        //             int dr[] = {0, 0, 1, -1};
        //             int dc[] = {1, -1, 0, 0};

        //             // Visit all the neighbouring cells.
        //             for(int k = 0;k < 4;k++){
        //                 int newi = i + dr[k];
        //                 int newj = j + dc[k];

        //                 // If the neighbouring cell has a larger value, then the maximum length of increasing path at this
        //                 // cell can be extended to the next cell. If it is greater than the previously calculated path then
        //                 // only the updation will take place.

        //                 if(newi >= 0 && newj >= 0 && newi < n && newj < m && matrix[newi][newj] > matrix[i][j]){
        //                     dp[newi][newj] = max(dp[newi][newj], 1 + dp[i][j]);
        //                 }
        //             }
        //         }

        //         for(int i = 0;i < n;i++){
        //             for(int j = 0;j < m;j++){
        //                 ans = max(ans, (long long)dp[i][j]);
        //             }
        //         }

        //         return ans;
    }
};
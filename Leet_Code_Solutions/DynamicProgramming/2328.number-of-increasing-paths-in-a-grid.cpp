class Solution
{
public:
    const int mod = 1e9 + 7;
    int dp[1001][1001];

    int dfs(int i, int j, vector<vector<int>> &grid)
    {
        if (dp[i][j] != 0)
        {
            return dp[i][j];
        }

        // dp[i][j] -> denotes the numbers of paths ending at (i, j).

        // These paths which are ending at (i, j) must have come from the four directions.

        // One path is consisting of itself.

        long long ans = 1;

        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};
        int n = grid.size(), m = grid[0].size();

        for (int k = 0; k < 4; k++)
        {
            int newi = i + dr[k];
            int newj = j + dc[k];

            if (newi >= 0 && newj >= 0 && newi < n && newj < m && grid[i][j] > grid[newi][newj])
            {
                ans = (ans + dfs(newi, newj, grid)) % mod;
            }
        }

        return dp[i][j] = ans % mod;
    }

    int countPaths(vector<vector<int>> &grid)
    {
        // 1) DFS with Memoisation.

        // Key Point -> Number of paths ending at (i, j).

        //         long long ans = 0;
        //         int n = grid.size();
        //         int m = grid[0].size();

        //         memset(dp, 0, sizeof(dp));

        //         for(int i = 0;i < n;i++){
        //             for(int j = 0;j < m;j++){
        //                 ans = (ans + dfs(i, j, grid)) % mod;
        //             }
        //         }

        //         return ans;

        // 2) DP + Sorting.

        // Key Concept -> Number of Paths ending at (i, j).
        // We have to calculate this for every cell..

        // key Concept : So here we update the neighbouring cells if they have larger value than the current cell.
        long long ans = 0;
        int n = grid.size(), m = grid[0].size();
        vector<pair<int, pair<int, int>>> arr;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                arr.push_back({grid[i][j], {i, j}});
            }
        }

        // So now the cells have been sorted by thier values.
        sort(arr.begin(), arr.end());

        // Let's implement the dp appraoch.

        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 1));

        for (auto currCell : arr)
        {
            int value = currCell.first;
            int i = currCell.second.first;
            int j = currCell.second.second;

            int dr[] = {0, 0, 1, -1};
            int dc[] = {1, -1, 0, 0};

            for (int k = 0; k < 4; k++)
            {
                int newi = i + dr[k];
                int newj = j + dc[k];
                // We check in all four directions.

                // If the neighbour of the current cell have a larger value then it will be updated.
                // As all the paths which are ending at this cell will be extending to that neighbouring cell.

                if (newi >= 0 && newj >= 0 && newi < n && newj < m && grid[i][j] < grid[newi][newj])
                {
                    dp[newi][newj] = (dp[newi][newj] + dp[i][j]) % mod;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans = (ans + dp[i][j]) % mod;
            }
        }

        return ans;
    }
};
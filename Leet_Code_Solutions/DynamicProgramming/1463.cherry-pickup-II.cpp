class Solution
{
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

        return solve(0, 0, m - 1, grid, dp);
    }

    int solve(int row, int col1, int col2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
    {
        int n = grid.size();
        int m = grid[0].size();

        if (row >= n)
            return 0;

        if (dp[row][col1][col2] != -1)
        {
            return dp[row][col1][col2];
        }

        int ans = 0;

        if (col1 == col2)
        {
            ans += grid[row][col1];
        }
        else
        {
            ans += grid[row][col1];
            ans += grid[row][col2];
        }
        int curr = 0;
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                if (col1 + i >= 0 && col1 + i < m && col2 + j >= 0 && col2 + j < m)
                {
                    curr = max(curr, solve(row + 1, col1 + i, col2 + j, grid, dp));
                }
            }
        }

        return dp[row][col1][col2] = ans + curr;
    }
};
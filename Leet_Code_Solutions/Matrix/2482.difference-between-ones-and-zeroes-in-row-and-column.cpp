class Solution
{
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        map<int, int> row;
        map<int, int> col;

        for (int i = 0; i < n; i++)
        {
            int ones = 0;
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                    ones++;
            }
            row[i] = ones;
        }

        for (int i = 0; i < m; i++)
        {
            int ones = 0;
            for (int j = 0; j < n; j++)
            {
                if (grid[j][i] == 1)
                    ones++;
            }
            col[i] = ones;
        }

        vector<vector<int>> ans(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans[i][j] = 2 * row[i] + 2 * col[j] - n - m;
            }
        }

        return ans;
    }
};
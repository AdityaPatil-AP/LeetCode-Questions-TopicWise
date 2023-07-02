class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        // Linear Traversal
        int cnt = 0;

        int n = grid.size();
        int m = grid[0].size();

        int rowIndex = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            while (rowIndex < m && grid[i][rowIndex] >= 0)
            {
                rowIndex++;
            }
            cnt += (m - rowIndex);
        }

        return cnt;
    }
};
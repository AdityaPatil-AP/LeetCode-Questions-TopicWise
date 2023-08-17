class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        // Either we can Use Recursion or BFS technique.
        int n = mat.size();
        int m = mat[0].size();

        if (n == 0 || m == 0)
            return {};

        // We are employing Multi-source bfs.
        // Here we enqueue all the cells which contain 1. And then keep on
        // updating the adjacent cells based on that.
        queue<pair<int, int>> q;

        int max_value = m + n - 2;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // If 0, then push in queue to find the answers for others.
                if (mat[i][j] == 0)
                {
                    q.push({i, j});
                }
                else
                {
                    // We will initialise it with the max_value.
                    mat[i][j] = max_value;
                }
            }
        }

        vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        while (!q.empty())
        {
            auto [row, col] = q.front();
            q.pop();

            for (auto [dr, dc] : directions)
            {
                int r = row + dr;
                int c = col + dc;

                if (r >= 0 && r < n && c >= 0 && c < m && mat[r][c] > mat[row][col] + 1)
                {
                    q.push({r, c});
                    mat[r][c] = mat[row][col] + 1;
                }
            }
        }

        return mat;
    }
};
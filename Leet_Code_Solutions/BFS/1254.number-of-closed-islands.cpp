class Solution
{
public:
    int closedIsland(vector<vector<int>> &grid)
    {
        // Ultimately, the question boils down to finding the number of connected components.
        // The connected components which are basically not containing any '0' on the boundary of the
        // grid.

        int count = 0;
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // if it is a land cell and it is not visited + it forms a closed island
                // then increment the count.
                if (grid[i][j] == 0 && !vis[i][j] && bfs(i, j, grid, vis, m, n))
                {
                    count++;
                }
            }
        }

        return count;
    }

    bool bfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &vis, int &m, int &n)
    {
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = true;

        // all four directions in which we can check the neighbours are land cell or not.
        vector<int> dr{1, -1, 0, 0};
        vector<int> dc{0, 0, -1, 1};

        // isClosed -> tells whether the current island is closed or not, on the basis of
        // whether the current cell is on the boundary or not.
        bool isClosed = true;

        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++)
            {
                int new_x = x + dr[k];
                int new_y = y + dc[k];
                if (x + dr[k] == m || x + dr[k] == -1 || y + dc[k] == n || y + dc[k] == -1)
                {
                    isClosed = false;
                }
                else if (grid[new_x][new_y] == 0 && !vis[new_x][new_y])
                {
                    vis[new_x][new_y] = true;
                    q.push({new_x, new_y});
                }
            }
        }

        return isClosed;
    }
};
class Solution
{
public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        // ans variable  stores the number of 1's which are enclosed by all zeroes, similar to
        // a island.
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // If a land cell has not been visited then visit it, and
                // and make a bfs call.
                if (!vis[i][j] && grid[i][j] == 1)
                {
                    int count = bfs(i, j, grid, vis, n, m);
                    ans += count;
                }
            }
        }

        return ans;
    }

    int bfs(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &vis, int &n, int &m)
    {
        vis[x][y] = true;
        queue<pair<int, int>> q;
        q.push({x, y});

        // We can find 1's in all four directions.
        vector<int> dr{0, 0, -1, 1};
        vector<int> dc{-1, 1, 0, 0};

        // keeps the count of 1's in the connected component.
        int count = 0;

        bool isEnclosed = true;

        while (!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            count += 1;

            for (int k = 0; k < 4; k++)
            {
                int new_i = i + dr[k];
                int new_j = j + dc[k];

                // if we go out of the bounds of the grid which means we are at a boundary cell.
                // Therefore our this connected component of 1's is not enclosed.
                if (new_i >= n || new_i < 0 || new_j < 0 || new_j >= m)
                {
                    isEnclosed = false;
                }

                else if (grid[new_i][new_j] == 1 && !vis[new_i][new_j])
                {
                    // then visit it and make a bfs call for it's neighbours now.
                    vis[new_i][new_j] = true;
                    q.push({new_i, new_j});
                }
            }
        }

        if (isEnclosed)
        {
            return count;
        }
        return 0;
    }
};
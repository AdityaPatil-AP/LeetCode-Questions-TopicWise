class Solution
{
public:
    int ans = INT_MAX;
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        if (grid[0][0] == 1)
        {
            return -1;
        }

        bfs(grid);
        if (ans == INT_MAX)
        {
            return -1;
        }
        return ans;
    }

    void bfs(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, 0));

        queue<pair<pair<int, int>, int>> q;

        q.push({{0, 0}, 1});

        // for all eight directions.
        vector<int> dr = {-1, -1, -1, 0, 1, 1, 1, 0};
        vector<int> dc = {-1, 0, 1, 1, 1, 0, -1, -1};

        while (!q.empty())
        {
            pair<pair<int, int>, int> curr = q.front();
            q.pop();

            int i = curr.first.first;
            int j = curr.first.second;
            int dist = curr.second;
            if (i == (n - 1) && j == (m - 1))
            {
                ans = min(ans, dist);
            }
            if (visited[i][j] == 1)
            {
                continue;
            }
            else
            {
                visited[i][j] = 1;
                for (int k = 0; k < 8; k++)
                {
                    int new_i = i + dr[k];
                    int new_j = j + dc[k];

                    if (new_i >= 0 && new_j >= 0 && new_i < n && new_j < m && grid[new_i][new_j] == 0)
                    {
                        q.push({{new_i, new_j}, dist + 1});
                    }
                }
            }
        }
    }
};
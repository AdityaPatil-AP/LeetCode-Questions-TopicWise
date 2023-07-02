class Solution
{
public:
    int maxDistance(vector<vector<int>> &grid)
    {
        // We have to use bfs.
        // Goal : For every land cell find the maximum distance(manhattan distance) water cell. Out
        // of all the values return the largest value.

        // How to implement??
        // Using the multi - source bfs.

        // Here our starting point can be all the cells which are marked with 1.
        // which are land cell.

        // Manhattan distance indicates that we can't move diagonally, only valid directions are
        // up, down, left and right.

        // For every land cell find the distance of theirs to the water cell that comes their way.

        // The maximum distance among all those cells will be our answer.

        // As in every step we are only moving by one unit. Using bfs traversal is effecient.

        int n = grid.size();

        int mt = 0;

        // config : {{i, j}, d}.
        queue<pair<pair<int, int>, int>> q;

        vector<vector<int>> vis(n, vector<int>(n, 0));

        // Push the starting points in queue.
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        // Direction in which we can move.
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!q.empty())
        {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int t = q.front().second;
            q.pop();

            mt = max(mt, t);

            for (int k = 0; k < 4; k++)
            {
                int new_i = i + dr[k];
                int new_j = j + dc[k];

                if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < n && grid[new_i][new_j] == 0 && !vis[new_i][new_j])
                {
                    q.push({{new_i, new_j}, t + 1});
                    vis[new_i][new_j] = 1;
                }
            }
        }

        return (mt == 0) ? -1 : mt;
    }
};
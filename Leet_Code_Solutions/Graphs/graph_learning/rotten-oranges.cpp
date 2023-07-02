class Solution
{
public:
    // Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>> &grid)
    {
        // Code here

        int n = grid.size();
        int m = grid[0].size();

        // Taking all the rotten oranges and put it in the queue.
        // Storing the indices and the time. {{i, j}, t}.
        queue<pair<pair<int, int>, int>> q;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Traverse across the grid and get me all the rotten oranges.
        int cntfresh = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                if (grid[i][j] == 1)
                    cntfresh++;
            }
        }

        // ans time.
        int mt = 0;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        int cnt = 0;
        while (!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();

            // Visit all the neighbouring the guys if not visited as well update time if
            // happens.
            mt = max(mt, t);

            // Traversing the neighbours.
            for (int i = 0; i < 4; i++)
            {
                int new_r = r + dr[i];
                int new_c = c + dc[i];

                // Check the validity first.
                if (new_r >= 0 && new_r < n && new_c >= 0 && new_c < m && !vis[new_r][new_c] &&
                    grid[new_r][new_c] == 1)
                {
                    q.push({{new_r, new_c}, t + 1});
                    vis[new_r][new_c] = 1;
                    cnt++;
                }
            }
        }

        if (cnt != cntfresh)
            return -1;
        // for(int i = 0;i < n;i++){
        //     for(int j = 0;j < m;j++){
        //         if(grid[i][j] == 1){
        //             return -1;
        //         }
        //     }
        // }
        return mt;
    }
};
class Solution
{
public:
    int shortestPathAllKeys(vector<string> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        // Storing the character to bitmask position for further calculations.
        unordered_map<char, int> key_bit;
        int bit_start = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (islower(grid[i][j]))
                    key_bit[grid[i][j]] = bit_start++;
            }
        }

        int mask_end = (1 << bit_start) - 1;
        int mask_size = (1 << bit_start);

        // This is different from standard bfs where we don't visit the cell back which took us here.
        // But In this case we visit the cell, our key holding state changes.
        // Which means that we are traversing in a new switched grid.
        // So we just have to make sure that we are revisiting a cell back for the same key holding
        // state back. So we have to make a visited array.
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(mask_size, false)));
        vector<int> start;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                if (grid[i][j] == '@')
                    start = {i, j, 0, 0};
        }

        // In standard traversal bfs we have {i, j, distance}.

        // But here we have to store the {i, j, distance, key_holding state}.

        // Using a mutable or iterable key holding state will increase the complexity. So we use
        // Bit Masking for this purpose.

        cout << bit_start << endl;

        queue<vector<int>> q;
        q.push(start);

        while (!q.empty())
        {
            vector<int> curr = q.front();
            q.pop();

            int i = curr[0];
            int j = curr[1];
            int distance = curr[2];
            int mask = curr[3];

            if (i < 0 || j < 0 || i >= m || j >= n)
                continue;

            if (grid[i][j] == '#')
                continue;

            if (isupper(grid[i][j]))
            {
                if ((mask & (1 << (key_bit[tolower(grid[i][j])]))) == 0)
                {
                    continue;
                }
            }

            if (islower(grid[i][j]))
                mask = mask | (1 << key_bit[grid[i][j]]);

            // If all the keys are found, return the distance.

            if (mask == mask_end)
                return distance;

            if (visited[i][j][mask] == true)
                continue;

            visited[i][j][mask] = true;

            int dr[] = {-1, 1, 0, 0};
            int dc[] = {0, 0, -1, 1};

            for (int k = 0; k < 4; k++)
            {
                q.push({i + dr[k], j + dc[k], distance + 1, mask});
            }
        }

        return -1;
    }
};

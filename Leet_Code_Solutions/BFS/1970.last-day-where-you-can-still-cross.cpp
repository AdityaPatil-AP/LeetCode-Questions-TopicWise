class Solution
{
public:
    int latestDayToCross(int row, int col, vector<vector<int>> &cells)
    {
        int days = 1;

        // I am going and checking for this day.

        map<pair<int, int>, int> mp; // on which day this cell was turned into a water cell.

        for (auto cell : cells)
        {
            mp[{cell[0] - 1, cell[1] - 1}] = days++;
        }

        int left = 0, right = cells.size();
        int ans = 0;
        while (left <= right)
        {
            int mid = (left + (right - left) / 2);

            if (bfsUsingMap(cells, row, col, mid, mp))
            {
                ans = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return ans;
    }

    bool bfsUsingMap(vector<vector<int>> &cells, int row, int col, int day, map<pair<int, int>, int> &mp)
    {
        vector<vector<int>> visited(row, vector<int>(col, 0));

        queue<pair<int, int>> q;
        for (int i = 0; i < col; i++)
        {
            if (mp[{0, i}] > day)
            {
                q.push({0, i});
            }
        }

        while (!q.empty())
        {
            auto curr = q.front();
            int i = curr.first;
            int j = curr.second;
            q.pop();

            if (visited[i][j] == true)
                continue;

            visited[i][j] = true;

            // // Check if it is a water cell or not.
            if (mp[{i, j}] <= day)
            {
                continue;
            }

            if (i == (row - 1))
                return true;

            int dr[] = {1, -1, 0, 0};
            int dc[] = {0, 0, -1, 1};

            for (int k = 0; k < 4; k++)
            {
                int newi = i + dr[k];
                int newj = j + dc[k];

                if (newi >= 0 && newi < row && newj >= 0 && newj < col)
                {
                    if (visited[newi][newj] == false && mp[{newi, newj}] > day)
                    {
                        q.push({newi, newj});
                    }
                }
            }
        }

        return false;
    }

    bool bfs(vector<vector<int>> &cells, int row, int col, int day)
    {
        vector<vector<int>> visited(row, vector<int>(col, 0));

        vector<vector<int>> grid(row, vector<int>(col, 0));

        for (int i = 0; i < day; i++)
        {
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }

        queue<pair<int, int>> q;
        for (int i = 0; i < col; i++)
        {
            if (grid[0][i] == 0)
            {
                q.push({0, i});
                visited[0][i] = true;
            }
        }

        while (!q.empty())
        {
            auto curr = q.front();
            int i = curr.first;
            int j = curr.second;
            q.pop();

            if (i == (row - 1))
                return true;

            int dr[] = {1, -1, 0, 0};
            int dc[] = {0, 0, -1, 1};

            for (int k = 0; k < 4; k++)
            {
                int newi = i + dr[k];
                int newj = j + dc[k];

                if (newi >= 0 && newi < row && newj >= 0 && newj < col)
                {
                    if (visited[newi][newj] == false && grid[newi][newj] == 0)
                    {
                        q.push({newi, newj});
                        visited[newi][newj] = true;
                    }
                }
            }
        }

        return false;
    }
};
class Solution
{
public:
    bool dfs(int i, int j, vector<vector<int>> &grid, int n, int m)
    {

        if (i == (n - 1) && j == (m - 1))
        {
            return true;
        }

        grid[i][j] = 0;

        int dr[] = {1, 0};
        int dc[] = {0, 1};

        for (int k = 0; k < 2; k++)
        {
            int newX = i + dr[k];
            int newY = j + dc[k];

            if (newX < n && newY < m && grid[newX][newY])
            {
                if (dfs(newX, newY, grid, n, m))
                {
                    return true;
                }
            }
        }

        return false;
    }

    bool isPossibleToCutPath(vector<vector<int>> &grid)
    {
        // Is it possible to make the matrix disconnect.

        // We can do a flipping operation.

        // That flipping can be done atmost once and not at (0, 0) and (n - 1, m - 1).

        // There are three cases for the current question.

        // 1) There is a common prefix path for every path from (0, 0) to (n - 1, m - 1).
        // So in this case we can easily flip any of the prefix path positions and the grid is disconnected.
        // So true for case one.

        // 2) There is a common point for two paths. Then if this path is flipped then the grid becomes disconnected
        // and the answer is true.

        // 3) There are two disconnected paths. In this case even if we flip all the cells of that path the answer
        // is false as the other path will take you to the final destination.

        // So we will work on the 3rd case and mark all the cells of the current path if it exists to 0.
        // and then go on searching for the other path. If we find one the answer is false or else the grid can
        // disconnected by atmost one flip operation.

        // This can be done using bfs Traversal or dfs traversal.
        int n = grid.size();
        int m = grid[0].size();

        if (dfs(0, 0, grid, n, m) == false)
        {
            return true;
        }
        grid[0][0] = 1;
        if (dfs(0, 0, grid, n, m) == false)
        {
            return true;
        }
        return false;
    }
};
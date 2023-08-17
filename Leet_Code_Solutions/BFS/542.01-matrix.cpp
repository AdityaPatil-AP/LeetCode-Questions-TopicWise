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

class Solution {
    public int[][] updateMatrix(int[][] mat) {
        if(mat == null || mat.length == 0 || mat[0].length == 0){
            return new int [0][0];
        }

        int m = mat.length, n = mat[0].length;

        Queue<int[]> queue = new LinkedList<>();

        int max_value = m + n - 2;

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(mat[i][j] == 0){
                    queue.offer(new int[]{i, j});
                }
                else{
                    mat[i][j] = max_value;
                }
            }
        }

        int[][] directions = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

        while(!queue.isEmpty()){
            int[] cell = queue.poll();
            for(int [] dir : directions){
                int r = cell[0] + dir[0], c = cell[1] + dir[1];

                if(r >= 0 && r < m && c >= 0 && c < n && mat[r][c] > mat[cell[0]][cell[1]] + 1){
                    queue.offer(new int[]{r, c});
                    mat[r][c] = mat[cell[0]][cell[1]] + 1;
                }
            }
        }

        return mat;
    }
}


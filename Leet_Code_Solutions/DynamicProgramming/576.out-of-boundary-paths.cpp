class Solution
{
public:
    const int mod = 1e9 + 7;
    vector<vector<vector<int>>> dp;
    int findPaths(int m, int n, int N, int x, int y)
    {
        // // Base Cases.
        // if(x == m || y == n || x < 0 || y < 0) return 1;
        // if(N == 0) return 0;

        // return findPaths(m, n, N - 1, x - 1, y)
        //     +  findPaths(m, n, N - 1, x, y - 1)
        //     +  findPaths(m, n, N - 1, x + 1, y)
        //     +  findPaths(m, n, N - 1, x, y + 1);

        dp = vector(m, vector<vector<int>>(n, vector<int>(N + 1, -1)));

        return totalPaths(m, n, N, x, y);
    }

    int totalPaths(int m, int n, int N, int x, int y)
    {
        if (x == m || y == n || x < 0 || y < 0)
            return 1;
        if (N == 0)
            return 0;

        if (dp[x][y][N] != -1)
            return dp[x][y][N];

        dp[x][y][N] = ((totalPaths(m, n, N - 1, x - 1, y) + totalPaths(m, n, N - 1, x, y - 1)) % mod + (totalPaths(m, n, N - 1, x + 1, y) + totalPaths(m, n, N - 1, x, y + 1)) % mod) % mod;

        return dp[x][y][N];
    }
};

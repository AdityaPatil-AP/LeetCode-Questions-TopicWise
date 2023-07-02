#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define mod 1000000007

int solve(int i, int j, vector<vector<char>> &grid, vector<vector<int>> &dp)
{
    int n = grid.size();

    if (grid[i][j] == '*')
    {
        return 0;
    }

    if (i == (n - 1) && j == (n - 1))
    {
        return 1;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    // bottom
    int bottom = 0, right = 0;
    if (i + 1 < n)
    {
        bottom = solve(i + 1, j, grid, dp);
    }

    if (j + 1 < n)
    {
        right = solve(i, j + 1, grid, dp);
    }

    return dp[i][j] = (right + bottom) % mod;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<char>> arr(n, vector<char>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    // vector<vector<int>> dp(n, vector<int>(n, -1));
    // int ans = solve(0, 0, arr, dp);
    // cout << ans << endl;

    // This answer can be space optimised as well.
    vector<vector<int>> dp(n, vector<int>(n, 0));

    dp[n - 1][n - 1] = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (i == n - 1 && j == n - 1)
            {
                dp[i][j] = 1;
            }

            if (arr[i][j] == '*')
            {
                dp[i][j] = 0;
            }
            else
            {
                if (i + 1 < n)
                    dp[i][j] = (dp[i][j] + dp[i + 1][j]) % mod;
                if (j + 1 < n)
                    dp[i][j] = (dp[i][j] + dp[i][j + 1]) % mod;
            }
        }
    }

    cout << dp[0][0] << endl;
    return 0;
}
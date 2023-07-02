#include <bits/stdc++.h>
using namespace std;

int n = 3, m = 3;

vector<vector<int>> grid(3, vector<int>(3));

vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(m, {-1, 0}));

// 0 -> take a down direction
// 1 -> right direction

int f(int i, int j)
{
    if (i >= n || j >= m)
    {
        return 1e9;
    }
    if (i == n - 1 && j == m - 1)
    {
        return grid[n - 1][m - 1];
    }

    // Use memoisation
    if (dp[i][j].first != -1)
    {
        return dp[i][j].first;
    }

    int ans1 = grid[i][j] + f(i + 1, j);
    int ans2 = grid[i][j] + f(i, j + 1);

    if (ans1 <= ans2)
    {
        dp[i][j].second = 0;
    }
    else
    {
        dp[i][j].second = 1;
    }

    return dp[i][j].first = min(ans1, ans2);
}

void solve()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> grid[i][j];
        }
    }

    cout << f(0, 0) << endl;

    // Constructing the actual path.
    cout << "Path is : " << endl;
    pair<int, int> current = {0, 0};
    while (current != make_pair(n - 1, m - 1))
    {
        cout << current.first << " " << current.second << endl;
        if (dp[current.first][current.second].second == 0)
        {
            // going down.
            current.first++;
        }
        else
        {
            // going right.
            current.second++;
        }
    }
    cout << current.first << " " << current.second << endl;
    return;
}

int main()
{
    solve();
    return 0;
}
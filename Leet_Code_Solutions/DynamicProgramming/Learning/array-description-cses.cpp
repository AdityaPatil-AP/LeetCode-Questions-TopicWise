#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define mod 1000000007

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);

    for (auto &x : arr)
        cin >> x;

    // state -> dp[x][i] -> Number of ways to fill till prefix [0.. i] when
    // the ith element is x.
    vector<vector<int>> dp(m + 1, vector<int>(n, 0));

    if (arr[0] == 0)
    {
        for (int i = 1; i <= m; i++)
        {
            dp[i][0] = 1;
        }
    }
    else
    {
        dp[arr[0]][0] = 1;
    }

    for (int j = 1; j < n; j++)
    {
        for (int i = 1; i <= m; i++)
        {

            if (arr[j] != 0 && arr[j] != i)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = ((long long)dp[i][j - 1]) % mod;
                if ((i - 1) >= 1)
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
                }
                if (i + 1 <= m)
                    dp[i][j] = (dp[i][j] + dp[i + 1][j - 1]) % mod;
            }
        }
    }

    long long ans = 0;

    for (int i = 1; i <= m; i++)
    {
        ans = (ans + dp[i][n - 1]) % mod;
    }

    cout << ans << endl;

    return 0;
}
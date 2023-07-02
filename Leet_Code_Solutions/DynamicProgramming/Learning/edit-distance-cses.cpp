#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long int

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();

    int dp[n + 1][m + 1];
    // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= m; i++)
    {
        dp[n][i] = m - i;
    }
    for (int j = 0; j <= n; j++)
    {
        dp[j][m] = n - j;
    }
    dp[n][m] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (s1[i] != s2[j])
            {
                dp[i][j] = 1 + min(dp[i + 1][j], min(dp[i][j + 1], dp[i + 1][j + 1]));
            }
            else
            {
                dp[i][j] = dp[i + 1][j + 1];
            }
        }
    }

    cout << dp[0][0] << endl;

    return 0;
}
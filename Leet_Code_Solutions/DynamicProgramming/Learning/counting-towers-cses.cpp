#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long int

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        // vector<vector<ll>> dp(2, vector<ll>(n, 0));
        ll dp[2][n];

        dp[0][n - 1] = 1;
        dp[1][n - 1] = 1;

        for (int i = n - 2; i >= 0; i--)
        {
            dp[0][i] = (4 * dp[0][i + 1] + dp[1][i + 1]) % 1000000007;
            dp[1][i] = (2 * dp[1][i + 1] + dp[0][i + 1]) % 1000000007;
        }

        cout << (dp[0][0] + dp[1][0]) % 1000000007 << endl;
    }
    return 0;
}
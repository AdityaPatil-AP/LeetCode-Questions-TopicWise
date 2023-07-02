#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define mod 1000000007

void solve()
{
    // find number of ways to make a sum of n from dice throws.

    // dp[i] = number of ways to make sum == i.
    // dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] .... dp[i - 6].

    // dp[n].
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (i - j >= 0)
                dp[i] += dp[i - j];
        }
    }

    cout << dp[n] << endl;
}
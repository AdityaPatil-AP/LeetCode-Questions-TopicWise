#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define mod 1000000007

vector<int> gather(int n)
{
    vector<int> ans;

    while (n > 0)
    {
        int rem = n % 10;
        if (rem != 0)
            ans.push_back(rem);
        n = n / 10;
    }

    return ans;
}

int solve(int n, vector<int> &dp)
{
    if (n == 0)
        return 0;

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int ans = 1e6 + 5;
    vector<int> digits = gather(n);
    for (int i = 0; i < digits.size(); i++)
    {
        ans = min(ans, 1 + solve(n - digits[i], dp));
    }

    return dp[n] = ans;
}

int main()
{
    int n;
    cin >> n;
    // vector<int> dp(n + 1, -1);
    // int ans = solve(n, dp);
    // cout << ans << endl;

    // Iterative Way.
    vector<int> dp(n + 1, 1e7);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        vector<int> digits = gather(i);
        for (int j = 0; j < digits.size(); j++)
        {
            dp[i] = min(dp[i], (1 + dp[i - digits[j]]));
        }
    }

    cout << dp[n] << endl;
    return 0;
}
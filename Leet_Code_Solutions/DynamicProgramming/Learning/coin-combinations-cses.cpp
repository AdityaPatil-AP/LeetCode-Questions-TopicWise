#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define mod 1000000007

int solve(int x, int n, vector<int> &arr, vector<int> &dp)
{
    if (x == 0)
    {
        return 1;
    }
    if (x < 0)
    {
        return 0;
    }

    if (dp[x] != -1)
        return dp[x];

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = (ans + solve(x - arr[i], n, arr, dp)) % mod;
    }

    return dp[x] = ans;
}

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (auto &x : arr)
        cin >> x;
    vector<int> dp(x + 1, -1);
    int ans = solve(x, n, arr, dp);
    cout << ans << endl;
    return 0;
}
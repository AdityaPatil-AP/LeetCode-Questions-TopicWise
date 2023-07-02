#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define mod 1000000007

int solve(vector<int> &arr, int n, int x, vector<int> &dp)
{
    if (x == 0)
    {
        return 0;
    }
    if (x < 0)
    {
        return 1e9;
    }
    if (dp[x] != -1)
        return dp[x];
    int ans = 1e9;
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, 1 + solve(arr, n, x - arr[i], dp));
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
    int ans = solve(arr, n, x, dp);
    if (ans > 1e6)
    {
        cout << "-1" << endl;
    }
    else
        cout << ans << endl;
    return 0;
}
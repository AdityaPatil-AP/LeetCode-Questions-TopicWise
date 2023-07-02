// state1 - dp[x][i] -> if currsum == x and last picked up element was ith element.
// then the number of ways to make sum == X.
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define mod 1000000007

// map<vector<int>, int> mp;

// int solve(int curr, int index, int x, vector<int> &arr, vector<vector<int>> &dp)
// {
//     if (curr > x || index == arr.size())
//     {
//         return 0;
//     }

//     if (curr == x)
//     {
//         return 1;
//     }

//     if (dp[curr][index] != -1)
//     {
//         return dp[curr][index];
//     }

//     // Now we can take any one of the denominations
//     int ans = 0;

//     ans = (ans + solve(curr + arr[index], index, x, arr, dp)) % mod;

//     ans = (ans + solve(curr, index + 1, x, arr, dp)) % mod;

//     return dp[curr][index] = ans;
// }

int main()
{
    int n, x;
    cin >> n >> x;
    int arr[n];
    for (auto &x : arr)
        cin >> x;
    sort(arr, arr + n);
    // vector<vector<int>> dp(x + 1, vector<int>(n + 1, -1));
    // int ans = solve(0, 0, x, arr, dp);
    // cout << ans << endl;

    // vector<vector<int>> dp(x + 1, vector<int>(n + 1, 0));
    int dp[n + 1][x + 1];

    for (int i = 0; i < n; i++)
    {
        dp[i][x] = 1;
    }

    for (int i = 0; i < x; i++)
    {
        dp[n][i] = 0;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = x - 1; j >= 0; j--)
        {
            dp[i][j] = dp[i + 1][j];
            if (j + arr[i] <= x)
            {
                dp[i][j] = (dp[i][j] + dp[i][j + arr[i]]) % mod;
            }
        }
    }

    cout << dp[0][0] << endl;
    return 0;
}

// state 2 - dp[x][i] -> number of ways to make sum == x using the first i coins
// #include <bits/stdc++.h>
// using namespace std;

// #define mod 1000000007

// int main()
// {

//     int n, target;
//     int mod = 1e9 + 7;
//     cin >> n >> target;

//     vector<int> arr(n);

//     for (int &x : arr)
//         cin >> x;

//     vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

//     // Base case.
//     dp[0][0] = 1;

//     for (int j = 1; j <= n; j++)
//     {
//         for (int i = 0; i <= target; i++)
//         {
//             // if we didn't pickup the current coin.
//             dp[j][i] = dp[j - 1][i];
//             int left = i - arr[j - 1];
//             if (left >= 0)
//             {
//                 (dp[j][i] += dp[j][left]) %= mod;
//             }
//         }
//     }

//     cout << dp[n][target] << endl;

// return 0;

// int mod = 1e9 + 7;
// int n, target;
// cin >> n >> target;
// vector<int> x(n);
// for (int &v : x)
//     cin >> v;

// vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
// dp[0][0] = 1;
// for (int i = 1; i <= n; i++)
// {
//     for (int j = 0; j <= target; j++)
//     {
//         dp[i][j] = dp[i - 1][j];
//         int left = j - x[i - 1];
//         if (left >= 0)
//         {
//             (dp[i][j] += dp[i][left]) %= mod;
//         }
//     }
// }
// cout << dp[n][target] << endl;
// }
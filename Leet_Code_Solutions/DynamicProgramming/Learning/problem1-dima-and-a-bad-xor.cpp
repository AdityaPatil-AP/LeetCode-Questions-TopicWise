#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> arr(n, vector<ll>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    vector<vector<pair<bool, ll>>> dp(n + 1, vector<pair<bool, ll>>(1024, {false, 0}));

    // State :
    // dp[i][x].first -> is it possible to make xor of x from
    // the first i rows.
    // dp[i][x].second -> will store the choice of column that we made.

    dp[0][0].first = true;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 1023; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (dp[i - 1][j ^ arr[i - 1][k]].first)
                {
                    dp[i][j].first = true;
                    dp[i][j].second = k; // We are storing our choices.
                    break;
                }
            }
        }
    }

    // final ans dp[n][i].first == true, the return true.
    for (int i = 1; i <= 1023; i++)
    {
        if (dp[n][i].first == true)
        {
            vector<int> choices(n);
            int row = n, xor_value = i;
            while (row != 0)
            {
                int choice = dp[row][xor_value].second;
                choices[row - 1] = choice + 1;

                // for the next iteration my xor will be.
                int new_xor = xor_value ^ arr[row - 1][choice];
                xor_value = new_xor;

                row--;
            }

            // Printing the possible answer choices
            cout << "TAK" << endl;
            for (auto i : choices)
            {
                cout << i << " ";
            }
            cout << endl;
            return 0;
        }
    }
    cout << "NIE" << endl;
    return 0;
}
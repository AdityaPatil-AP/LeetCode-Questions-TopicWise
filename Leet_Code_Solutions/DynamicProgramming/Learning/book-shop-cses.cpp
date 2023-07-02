
#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long int

int main()
{
    int n, money;
    cin >> n >> money;
    vector<int> price(n);
    vector<int> pages(n);

    for (auto &x : price)
        cin >> x;
    for (auto &x : pages)
        cin >> x;

    vector<vector<int>> dp(n + 1, vector<int>(money + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= money; j++)
        {
            // don't buy the book.
            dp[i][j] = dp[i - 1][j];

            if (j - price[i - 1] >= 0)
            {
                dp[i][j] = max(dp[i][j], pages[i - 1] + dp[i - 1][j - price[i - 1]]);
            }
        }
    }

    // Final Subproblem -> to find the maximum number of pages that we can buy by choosing any book atmost once
    // and spending atmost x money.
    cout << dp[n][money] << endl;

    return 0;
}
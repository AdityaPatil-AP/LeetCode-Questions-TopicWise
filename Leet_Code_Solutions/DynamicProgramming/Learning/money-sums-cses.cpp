#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long int
#define macro int

int main()
{

    // Checking for a possibility question.
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (auto &x : arr)
        cin >> x;

    // vector<vector<int>> dp(n + 1, vector<int>(1e5 + 1, false));

    // Space Optimisation.
    vector<ll>
        prev(1e5 + 1, false);

    prev[0] = true;

    for (int i = 1; i <= n; i++)
    {
        vector<ll> curr(1e5 + 1, false);
        int currDenomination = arr[i - 1];
        for (int val = 0; val <= 1e5; val++)
        {
            if (prev[val])
            {
                // If val was possible for the last denomination.
                // the we have two options for it.
                // either take it or leave it.

                // 1) take it.
                int newval = val + currDenomination;
                if (newval <= 1e5 && newval >= 0)
                {
                    curr[newval] = true;
                }

                // not+_take.
                if (val >= 0)
                    curr[val] = true;
            }
        }
        prev = curr;
    }

    vector<ll> ans;
    for (int i = 1; i <= 1e5; i++)
    {
        if (prev[i])
        {
            ans.push_back(i);
        }
    }

    cout << ans.size() << endl;
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
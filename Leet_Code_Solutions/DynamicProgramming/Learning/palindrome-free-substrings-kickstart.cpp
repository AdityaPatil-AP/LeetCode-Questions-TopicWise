#include <bits/stdc++.h>
using namespace std;

#define ll long long int

bool notPalindrome(string s1)
{
    string rev = s1;
    reverse(rev.begin(), rev.end());
    return (rev != s1);
}

int helper(string prev, int index, string s, vector<map<string, int>> &dp)
{

    if (index == s.size())
    {
        return 1;
    }
    if (dp[index].find(prev) != dp[index].end())
    {
        return dp[index][prev];
    }

    string x1 = prev.substr(1, 4);
    string x2 = prev.substr(1, 4);
    x1 += '0';
    x2 += '1';

    int ans = 0;

    if (s[index] == '?')
    {
        // checking if the length 5 and length 6 palindrome are not
        // present.
        if (notPalindrome(x1) && notPalindrome(prev + '0'))
        {
            ans += helper(x1, index + 1, s, dp);
        }
        if (notPalindrome(x2) && notPalindrome(prev + '1'))
        {
            ans += helper(x2, index + 1, s, dp);
        }
    }
    else if (s[index] == '1')
    {
        if (notPalindrome(x2) && notPalindrome(prev + '1'))
        {
            ans += helper(x2, index + 1, s, dp);
        }
    }
    else
    {
        if (notPalindrome(x1) && notPalindrome(prev + '0'))
        {
            ans += helper(x1, index + 1, s, dp);
        }
    }

    dp[index][prev] = ans;
    return ans;
}

int main()
{
    // test case constraints are 5 * (10^4).
    // in such cases uses recursive dp because you don't go
    // and compute unnecessary states.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        // map<pair<int, string>, int> dp;
        vector<map<string, int>> dp(n, map<string, int>());
        // At the start the last characters are random.
        cout << "Case #" << i << ": " << (helper("?????", 0, s, dp) ? "POSSIBLE" : "IMPOSSIBLE") << endl;
    }
    return 0;
}
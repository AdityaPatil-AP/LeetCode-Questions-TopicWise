#define ll long long int
#define mod 1000000007
class Solution
{
public:
    ll solve(int length, int &zero, int &one, vector<ll> &dp)
    {

        if (length == 0)
        {
            return 1;
        }
        if (length < 0)
        {
            return 0;
        }
        if (dp[length] != -1)
        {
            return dp[length];
        }

        // If i take '0' zero times, then the number of ways to create 'length' sized string
        ll takeZero = solve(length - zero, zero, one, dp);

        // If i take '1' one times, then the number of ways to create 'length' sized string.
        ll takeOne = solve(length - one, zero, one, dp);

        return dp[length] = ((takeZero + takeOne) % mod);
    }

    int countGoodStrings(int low, int high, int zero, int one)
    {
        ll ans = 0;
        vector<ll> dp(high + 1, -1);
        for (int i = low; i <= high; i++)
        {
            // if(dp[i] == -1) dp[i] = 0;
            ans = (ans + solve(i, zero, one, dp)) % mod;
        }
        return ans;
    }
};
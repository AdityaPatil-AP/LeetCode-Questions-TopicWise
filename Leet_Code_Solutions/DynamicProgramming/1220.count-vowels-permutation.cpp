class Solution
{
public:
    const int mod = 1e9 + 7;
    vector<vector<int>> dp;
    int helper(int i, int n, char prev)
    {
        if (i == n)
        {
            return 1;
        }

        if (dp[i][prev - 'a'] != -1)
        {
            return dp[i][prev - 'a'];
        }
        long long ans = 0;
        if (prev == 'a')
        {
            ans = helper(i + 1, n, 'e');
        }
        else if (prev == 'e')
        {
            ans = helper(i + 1, n, 'a');
            ans = (ans + helper(i + 1, n, 'i')) % mod;
        }
        else if (prev == 'i')
        {
            ans = helper(i + 1, n, 'a');
            ans = (ans + helper(i + 1, n, 'e')) % mod;
            ans = (ans + helper(i + 1, n, 'o')) % mod;
            ans = (ans + helper(i + 1, n, 'u')) % mod;
        }
        else if (prev == 'o')
        {
            ans = helper(i + 1, n, 'i');
            ans = (ans + helper(i + 1, n, 'u')) % mod;
        }
        else
        {
            ans = helper(i + 1, n, 'a');
        }

        return dp[i][prev - 'a'] = ans % mod;
    }

    int countVowelPermutation(int n)
    {
        long long ans = 0;
        dp = vector(n, vector(26, -1));
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        for (int i = 0; i < 5; i++)
        {
            ans = (ans + helper(1, n, vowels[i])) % mod;
        }

        return ans;
    }
};
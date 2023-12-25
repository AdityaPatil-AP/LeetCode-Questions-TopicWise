class Solution
{
public:
    int numDecodings(string s)
    {
        // dp[i] -> Number of ways to decode the string from ith position till end.
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[n] = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '0')
            {
                continue;
            }
            string s1 = s.substr(i, 1);

            dp[i] += dp[i + 1];
            if (i + 1 < n)
            {
                string s2 = s.substr(i, 2);
                if (stoi(s2) <= 26)
                    dp[i] += dp[i + 2];
            }
        }

        return dp[0];
    }
};
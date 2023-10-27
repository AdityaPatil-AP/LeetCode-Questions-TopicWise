class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, false));
        int start = 0, end = 0;
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = true;
            if (i + 1 < n)
            {
                if (s[i] == s[i + 1])
                {
                    dp[i][i + 1] = true;
                    start = i;
                    end = i + 1;
                }
            }
        }
        // dp[i][j] -> signifies whether the substring of s[i, j] is a palindrome or not.
        int ans = (end - start + 1);
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if (i + 1 <= j - 1)
                {
                    if (s[i] == s[j])
                    {
                        dp[i][j] = dp[i + 1][j - 1];
                        if (dp[i][j])
                        {
                            if (ans < (j - i + 1))
                            {
                                start = i;
                                end = j;
                                ans = (j - i + 1);
                            }
                        }
                    }
                    else
                    {
                        dp[i][j] = false;
                    }
                }
            }
        }

        return s.substr(start, (end - start + 1));
    }
};
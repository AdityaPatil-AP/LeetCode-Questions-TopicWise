class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int n = s.size();
        int m = p.size();
        // vector<vector<int>> dp(n + 1, vector<int>(m, -1));
        // return solve(0, 0, s, p, dp);

        // another way.
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return solution(s, p, n - 1, m - 1, dp);

        // State way.
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Base Case :
        // 1) empty string matches with empty pattern.
        dp[0][0] = true;
        // 2) then if pattern is consumed but string is still not consumed.
        // dp[i][0] = false;
        // 3) if string is consumed but pattern is still remaining.
        for (int j = 1; j <= m; j++)
        {
            if (p[j - 1] == '*')
            {
                dp[0][j] = true;
            }
            else
                break;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                // Case of a match.
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[j - 1] == '*')
                {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
                // no match case.
                else
                {
                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m];
    }

    bool solution(string &s, string &p, int i, int j, vector<vector<int>> &dp)
    {
        // Base Case
        if (i < 0 && j < 0)
            return true;
        // My string has not been consumed but the pattern is already consumed.
        // in that case return false.
        if (i >= 0 && j < 0)
            return false;
        // My string has been consumed but the pattern is still not consumed.
        // Here we encounter two cases.
        if (i < 0 && j >= 0)
        {
            return (p[j] == '*' && solution(s, p, i, j - 1, dp));
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        // match.
        if (s[i] == p[j] || p[j] == '?')
        {
            return dp[i][j] = solution(s, p, i - 1, j - 1, dp);
        }
        else if (p[j] == '*')
        {
            return dp[i][j] = solution(s, p, i - 1, j, dp) || solution(s, p, i, j - 1, dp);
        }

        return dp[i][j] = false;
    }

    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp)
    {
        int n = s.size();
        int m = p.size();

        if (i == n && j == m)
        {
            return true;
        }
        else if (j == m)
        {
            return false;
        }
        else if (i > n)
        {
            return false;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (p[j] == '*')
        {
            // Two options either match and remain on the same position of the pattern.
            bool option1 = solve(i + 1, j, s, p, dp);

            // match and move ahead.
            bool option2 = solve(i + 1, j + 1, s, p, dp);

            // don't match and move ahead.
            bool option3 = solve(i, j + 1, s, p, dp);

            if (option1 || option2 || option3)
            {
                return dp[i][j] = true;
            }
        }
        else if (p[j] == '?')
        {
            return dp[i][j] = solve(i + 1, j + 1, s, p, dp);
        }
        else if (i != n && p[j] == s[i])
        {
            return dp[i][j] = solve(i + 1, j + 1, s, p, dp);
        }
        return dp[i][j] = false;
    }
};
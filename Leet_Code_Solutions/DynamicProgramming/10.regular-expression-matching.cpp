class Solution
{
public:
    bool helper(string &s, string &p, int i, int j, vector<vector<int>> &dp)
    {
        if (j == p.size())
        {
            return i == s.size();
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        bool first_match = (i < s.size() && (p[j] == '.' || (p[j] == s[i])));

        if (j + 1 < p.size() && p[j + 1] == '*')
        {
            return dp[i][j] = (helper(s, p, i, j + 2, dp) || (first_match && helper(s, p, i + 1, j, dp)));
        }
        else
        {
            return dp[i][j] = (first_match && helper(s, p, i + 1, j + 1, dp));
        }
    }

    bool isMatch(string s, string p)
    {
        // cases :
        // 1) normal match.
        // 2) . then a *
        // 3) * then a *
        // 4) .
        // 5) * then a .
        // There are multiple scenarios, we will start by solving it through recursion.
        // Using recursion and Memoisation.
        // In memoistaion we have to keep answers computed for every i and j. Therefore.
        // vector<vector<int>> dp(s.size() + 1, vector<int> (p.size() + 1, -1));
        // return helper(s, p, 0, 0, dp);

        // bottom up approach
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, 0));
        dp[s.size()][p.size()] = 1;

        for (int i = s.size(); i >= 0; i--)
        {
            for (int j = p.size() - 1; j >= 0; j--)
            {
                bool first_match = (i < s.size() && (p[j] == '.' || (s[i] == p[j])));
                if (j + 1 < p.size() && p[j + 1] == '*')
                {
                    dp[i][j] = (dp[i][j + 2] || (first_match && dp[i + 1][j]));
                }
                else
                {
                    dp[i][j] = (first_match && dp[i + 1][j + 1]);
                }
            }
        }
        return dp[0][0];

        // return regex_match(s, regex(p));
    }
};
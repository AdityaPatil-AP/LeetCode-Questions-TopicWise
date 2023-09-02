class Solution
{
public:
    int minExtraChar(string s, vector<string> &dictionary)
    {
        unordered_map<string, bool> isPresent;

        for (int i = 0; i < dictionary.size(); i++)
        {
            isPresent[dictionary[i]] = true;
        }

        int n = s.size();

        vector<int> dp(n, 1e9);

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                string curr = s.substr(i, j - i + 1);
                // If the word is present.
                if (isPresent[curr])
                {
                    if (i - 1 < 0)
                    {
                        dp[j] = min(dp[j], 0);
                    }
                    else
                        dp[j] = min(dp[j], dp[i - 1]);
                }
                // If the word is not present.
                if (i - 1 < 0)
                    dp[j] = min(dp[j], (j - i + 1));
                else
                    dp[j] = min(dp[j], dp[i - 1] + (j - i + 1));
            }
        }

        return dp[n - 1];
    }
};
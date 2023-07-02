// Bottom up and top down.

class Solution
{
public:
    int numWays(vector<string> &words, string target)
    {
        // Recursive Way.
        // Parameters -> index of string from where matching is remaining, index of last character matched from words,
        // words vector, and target string.
        // Precomputation.
        // const int alphabet = 26;
        // int k = words[0].size();
        // vector cnt(alphabet, vector<int>(k));
        // for (int j = 0; j < k; j++) {
        //     for (const string& word : words) {
        //         cnt[word[j] - 'a'][j]++;
        //     }
        // }
        // // Memoisation.
        // vector<vector<int>> dp(target.size(), vector<int>(words[0].size() + 1, -1));
        // return solve(0, 0, target, cnt, dp);

        // Bottom Up Approach.
        // -> first there are two parameters for our dp state.
        // -> 1) We require the index of the target string we built till now.
        // -> 2) What was the last index which we used to match the target character.

        // State -> dp[i][k].
        int n = target.size();
        int m = words[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Creation of freq array.
        vector<vector<int>> freq(26, vector<int>(m, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < words.size(); j++)
            {
                char m = words[j][i];
                freq[m - 'a'][i]++;
            }
        }

        // Base Case

        for (int i = 0; i <= m; i++)
        {
            dp[n][i] = 1;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                int pickWays = 0;
                char curr = target[i];
                if (freq[curr - 'a'][j] > 0)
                {
                    int count = freq[curr - 'a'][j];
                    pickWays = ((long long)count * dp[i + 1][j + 1]) % 1000000007;
                }
                int notPickWays = dp[i][j + 1];

                dp[i][j] = ((long long)pickWays + notPickWays) % 1000000007;
            }
        }

        return dp[0][0];
    }

    int solve(int index, int last, string &target, vector<vector<int>> &cnt, vector<vector<int>> &dp)
    {
        if (index == target.size())
        {
            return 1;
        }
        // All the characters are exhausted in words array then we cannot form our target string.
        if ((cnt[0].size()) == last)
        {
            return 0;
        }

        if (dp[index][last] != -1)
        {
            return dp[index][last];
        }
        int numWays = 0;
        int notPickWays = solve(index, last + 1, target, cnt, dp);
        int curr = target[index];
        int pickWays = 0;
        int count = cnt[curr - 'a'][last];
        if (count > 0)
            pickWays = ((long long)numWays + (long long)count * solve(index + 1, last + 1, target, cnt, dp)) % (1000000007);

        return dp[index][last] = ((long long)notPickWays + pickWays) % (1000000007);
    }
};

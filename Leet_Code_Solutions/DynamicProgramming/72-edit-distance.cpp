class Solution
{
public:
    int minOperations(int i, int j, string word1, string word2, vector<vector<int>> &dp)
    {
        int n = word1.size();
        int m = word2.size();
        if (j == m)
        {
            // If our word2 has been matched but still some character of i are remaining,
            // then we have to delete them.
            return (n - i);
        }

        if (i == n)
        {
            // If the word1 is exhausted but some character of word2 has to be matched, then
            // we have to insert the matching characters in word1.
            return (m - j);
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        // If they match we don't have to do anything.
        if (word1[i] == word2[j])
        {
            return minOperations(i + 1, j + 1, word1, word2, dp);
        }

        // As discussed there are three operations : 1) insert, 2) delete, 3) replace.

        // 1) insert.
        int case1 = 1 + minOperations(i, j + 1, word1, word2, dp);

        // 2) delete
        int case2 = 1 + minOperations(i + 1, j, word1, word2, dp);

        // 3) replace
        int case3 = 1 + minOperations(i + 1, j + 1, word1, word2, dp);

        int ans = min(case1, min(case2, case3));

        return dp[i][j] = ans;
    }

    int minDistance(string word1, string word2)
    {
        // 1) If i insert a matching character, then the index of word1 will not
        // increase, but the index of the word2 will increase.

        // 2) If i replace a character to the character similar to word2, then the index of both
        // the word1 and word2 will increase.

        // 3) Delete, In this we move the next index of the word1.

        //         int n = word1.size();
        //         int m = word2.size();

        //         vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        //         return minOperations(0, 0, word1, word2, dp);

        // Bottom Up Approach.
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= n; i++)
        {
            dp[i][m] = n - i;
        }

        for (int j = 0; j <= m; j++)
        {
            dp[n][j] = m - j;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (word1[i] == word2[j])
                {
                    dp[i][j] = dp[i + 1][j + 1];
                }
                else
                {
                    // Insert.
                    int case1 = 1 + dp[i][j + 1];
                    // replace
                    int case2 = 1 + dp[i + 1][j + 1];
                    // delete.
                    int case3 = 1 + dp[i + 1][j];

                    dp[i][j] = min(case1, min(case2, case3));
                }
            }
        }

        return dp[0][0];
    }
};
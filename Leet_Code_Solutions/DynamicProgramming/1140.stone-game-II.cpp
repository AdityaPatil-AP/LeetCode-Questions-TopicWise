class Solution
{
public:
    int stoneGameII(vector<int> &piles)
    {
        // Recursion.

        //         int n = piles.size();

        //         // The first turn is Alice's turn so set the turn variable as true.
        //         int ans = helper(0, piles, 1, true);

        //         return ans;

        int length = piles.size();
        vector<vector<int>> dp(length + 1, vector<int>(length + 1, 0));
        vector<int> sufsum(length + 1, 0);
        for (int i = length - 1; i >= 0; i--)
        {
            sufsum[i] = sufsum[i + 1] + piles[i];
        }
        for (int i = 0; i <= length; i++)
        {
            dp[i][length] = sufsum[i];
        }
        for (int i = length - 1; i >= 0; i--)
        {
            for (int j = length - 1; j >= 1; j--)
            {
                for (int X = 1; X <= 2 * j && i + X <= length; X++)
                {
                    dp[i][j] = max(dp[i][j], sufsum[i] - dp[i + X][max(j, X)]);
                }
            }
        }
        return dp[0][1];
    }

    int helper(int index, vector<int> &piles, int m, bool turn)
    {

        int n = piles.size();

        if (index >= n)
        {
            return 0;
        }

        int ans = 0;

        // for every value in turn.
        for (int i = index; i < n && i < (index + 2 * m); i++)
        {
            if (turn)
            {
                // sum calculation.
                // Prefix Sum.
                int psum = 0;
                for (int j = index; j <= i; j++)
                {
                    psum += piles[j];
                }

                ans = max(ans, psum + helper(i + 1, piles, max(m, i - index + 1), false));
            }
            else
            {
                ans = max(helper(i + 1, piles, max(m, i - index + 1), true), ans);
            }
        }

        return ans;
    }
};
class Solution
{
public:
    long long int count(int coins[], int N, int sum)
    {

        // code here.
        // Memoisation.

        // vector<vector<long long int>> dp(N, vector<long long int> (sum + 1, -1));
        // long long int ans = helper(0, 0, coins, N, sum, dp);
        // return ans;

        // Tabulation Format.

        vector<vector<long long int>> dp(N + 1, vector<long long int>(sum + 1, 0));

        dp[N][sum] = 1;

        for (int i = N - 1; i >= 0; i--)
        {
            for (int j = sum; j >= 0; j--)
            {

                long long pick = 0, not_pick = 0;
                if (j + coins[i] <= sum)
                {
                    pick = dp[i][j + coins[i]];
                }
                not_pick = dp[i + 1][j];

                dp[i][j] = pick + not_pick;
            }
        }

        return dp[0][0];
    }

    long long int helper(int index, int gathered_sum, int coins[], int N, int sum, vector<vector<long long int>> &dp)
    {
        if (index == N)
        {
            return (gathered_sum == sum);
        }

        if (gathered_sum > sum)
        {
            return 0;
        }

        if (dp[index][gathered_sum] != -1)
        {
            return dp[index][gathered_sum];
        }

        // Two options.
        // pick it.
        long long int pick = helper(index, gathered_sum + coins[index], coins, N, sum, dp);

        // not pick the current denomination.
        long long int not_pick = helper(index + 1, gathered_sum, coins, N, sum, dp);

        return dp[index][gathered_sum] = (pick + not_pick);
    }
};
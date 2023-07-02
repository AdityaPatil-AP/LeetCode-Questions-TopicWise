class Solution
{
public:
    const int mod = 1e9 + 7;

    long long dp[105][205];

    int countRoutes(vector<int> &locations, int start, int finish, int fuel)
    {
        //         memset(dp, -1, sizeof(dp));
        //         int ans = helper(start, finish, fuel, locations);

        //         return ans;

        // In State Formation terms.

        // I can define a state as,

        // dp[i][j] -> Number of routes to go from city i to city finish when you have j amount of
        //             fuel remaining.

        // Formation of valid State Transition Equation.
        //
        // dp[i][j] -> (dp[i][j] + dp[k][j - abs(locations[j] - locations[k])]) % mod; // where k is some other city.

        // Base Case, dp[finish][j] = 1; j >= 0.

        // Final Subproblem -> dp[start][fuel].
        int n = locations.size();

        vector<vector<long long>> dp(n + 1, vector<long long>(fuel + 1, 0));

        // Base Case.
        for (int j = 0; j <= fuel; j++)
        {
            dp[finish][j] = 1;
        }

        for (int j = 0; j <= fuel; j++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int k = 0; k < n; k++)
                {
                    if (i != k)
                    {
                        if (abs(locations[i] - locations[k]) <= j)
                        {
                            dp[i][j] = (dp[i][j] + dp[k][j - abs(locations[i] - locations[k])]) % mod;
                        }
                    }
                }
            }
        }

        return dp[start][fuel];
    }

    int helper(int start, int finish, int fuel, vector<int> &locations)
    {
        if (fuel < 0)
        {
            return 0;
        }
        int n = locations.size();

        if (dp[start][fuel] != -1)
        {
            return dp[start][fuel];
        }
        long long ans = 0;
        if (start == finish)
        {
            ans = 1;
        }

        // We are at start and we can move to any location we want if we have enough fuel to do so.
        for (int i = 0; i < n; i++)
        {
            if (i != start)
            {
                ans = (ans + helper(i, finish, fuel - abs(locations[i] - locations[start]), locations)) % mod;
            }
        }

        return dp[start][fuel] = ans;
    }
};
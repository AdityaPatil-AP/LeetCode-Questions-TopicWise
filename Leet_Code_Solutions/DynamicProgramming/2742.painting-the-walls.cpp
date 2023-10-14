class Solution
{
public:
    int dp[505][505];

    int paintWalls(vector<int> &cost, vector<int> &time)
    {
        // Binary Search can't be applied.
        // Because we have to explore all the ways.

        // KnapSack Dp.
        // Typical - (take + not_take problem).

        // Inference - If we take a wall painted by a paid painter, then we can skip time[i] walls
        // Why? - Because they can be painted by free painter for 0 cost in 1 unit of time per each
        //        wall.

        // So here we can see the application of either selecting the current wall for the paid
        // painter or to skip it.
        //         int n = time.size();
        //         memset(dp, -1, sizeof(dp));
        //         int ans = findCost(cost, time, 0, n);

        //         return ans;

        // KnapSack dp.

        // dp[t] = c -> Minimum cost to paint t walls is c.
        int n = cost.size();
        vector<int> dp(n + 1, 1e9);

        dp[0] = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = n; j > 0; j--)
            {
                dp[j] = min(dp[j], dp[max(j - time[i] - 1, 0)] + cost[i]);
            }
        }

        return dp[n];
    }

    int findCost(vector<int> &cost, vector<int> &time, int i, int wallsRemaining)
    {
        int n = cost.size();
        if (wallsRemaining <= 0)
            return 0;

        if (i >= n)
        {
            return 1e9;
        }

        if (dp[i][wallsRemaining] != -1)
        {
            return dp[i][wallsRemaining];
        }

        // Either skip this wall to be painted by the paid painter.
        int skip = findCost(cost, time, i + 1, wallsRemaining);

        // Take it - cost if painted by the paid painter.
        int take = cost[i] + findCost(cost, time, i + 1, wallsRemaining - time[i] - 1);

        return dp[i][wallsRemaining] = min(take, skip);
    }
};

class Solution
{
public:
    vector<vector<int>> dp;

    int paintWalls(vector<int> &cost, vector<int> &time)
    {
        // When some paid painter is painting then we can use a free painter.

        // At a particular index, I have two choices Either I use a
        // 1) That Index as a wall painted by a paid painter and decrement the remaining
        // walls to be painted by (1 + time[i]) -> because in the mean time the free
        // painter will paint the time[1] walls for 0 money.
        // 2) the paid painter don't paint the wall and move ahead.

        // Base case: 1) If the remaining walls to be painted goes below 0, then return 0.
        // 2) Else we reach the end, but still some walls are remaining to be painted.
        // int n = cost.size();
        // dp = vector(n, vector(n + 1, -1));
        // return finder(0, n, cost, time);

        // Bottom Up Approach.
        // parameters : i, remain(The number of walls remaining which would be painted by free painters.).
        int n = cost.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        // If there 0 walls remaining then we can say the cost is 0.
        for (int i = 1; i <= n; i++)
        {
            dp[n][i] = 1e9;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            for (int remain = 1; remain <= n; remain++)
            {
                // Two options for paid painter
                // Free painter is dependent on the works of paid painter.

                //  we can either paint the current wall.
                int paint = cost[i] + dp[i + 1][max(0, remain - 1 - time[i])];

                // or skip it.
                int dontPaint = dp[i + 1][remain];

                dp[i][remain] = min(paint, dontPaint);
            }
        }

        return dp[0][n];
    }

    int finder(int i, int remain, vector<int> &cost, vector<int> &time)
    {
        if (remain <= 0)
        {
            return 0;
        }
        int n = cost.size();
        if (i == n)
        {
            return 1e9;
        }

        if (dp[i][remain] != -1)
        {
            return dp[i][remain];
        }

        // This index is painted by the paid painter.
        int paint = cost[i] + finder(i + 1, remain - 1 - time[i], cost, time);

        // The index is not painted by the paid painter, it is expected to be painted by
        // free painter for 0 cost.
        int dontPaint = 0 + finder(i + 1, remain, cost, time);

        return dp[i][remain] = min(paint, dontPaint);
    }
};
class Solution
{
public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        // Recursion and Memoisation.
        // vector<int> dp(366, -1);

        //         set<int> st;
        //         for(int i = 0;i < days.size();i++) st.insert(days[i]);

        //         return solve(1 , st, dp, costs);

        // Using Tabulation.
        // Using day variant.
        //         vector<int> dp(400, 0);

        //         dp[366] = 0;
        //         set<int> st;
        //         for(int i = 0;i < days.size();i++) st.insert(days[i]);
        //         for(int i = 365;i >= 0;i--){
        //             if(st.count(i) != 0){
        //                 dp[i] = min(costs[0] + dp[i + 1], min(costs[1] + dp[i + 7], costs[2] + dp[i + 30]));
        //             }
        //             else{
        //                 dp[i] = dp[i + 1];
        //             }
        //         }

        //         return dp[0];

        // Using Window Variant.
        // dp[i] -> cost to travel from days of i to the end of the plan.

        //         vector<int> dp(days.size() + 1, -1);

        //         return solve(0, dp, costs, days);

        // 2 Variant - the cost required for travelling from days[i] to the end of the plan.

        vector<int> durations = {1, 7, 30};

        int n = days.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            int j = i;

            for (int k = 0; k < 3; k++)
            {
                while (j < n && days[j] < days[i] + durations[k])
                {
                    j++;
                }
                dp[i] = min(dp[i], dp[j] + costs[k]);
            }
        }

        return dp[0];
    }

    int solve(int index, vector<int> &dp, vector<int> &costs, vector<int> &days)
    {
        if (index >= days.size())
        {
            return 0;
        }

        if (dp[index] != -1)
        {
            return dp[index];
        }

        int ans = INT_MAX;
        int j = index;

        vector<int> durations = {1, 7, 30};
        for (int k = 0; k < 3; ++k)
        {
            while (j < days.size() && days[j] < days[index] + durations[k])
            {
                j++;
            }
            ans = min(ans, solve(j, dp, costs, days) + costs[k]);
        }

        return dp[index] = ans;
    }

    //     int solve(int day, set<int> &st, vector<int> &dp, vector<int> &costs){
    //         if(day > 365){
    //             return 0;
    //         }
    //         if(dp[day] != -1){
    //             return dp[day];
    //         }

    //         int ans;
    //         // If we have to travel on that day, then we have three choices,
    //         // but if we don't have to travel we can directly avoid to take a pass and move on to
    //         // the next day.
    //         if(st.count(day) != 0){
    //             int oneDay = costs[0] + solve(day + 1, st, dp, costs);
    //             int sevenDay = costs[1] + solve(day + 7, st, dp, costs);
    //             int thirtyDay = costs[2] + solve(day + 30, st, dp, costs);
    //             ans = min(oneDay, min(sevenDay, thirtyDay));

    //         }
    //         else{
    //             ans = solve(day + 1, st, dp, costs);
    //         }

    //         return dp[day] = ans;
    //     }
};
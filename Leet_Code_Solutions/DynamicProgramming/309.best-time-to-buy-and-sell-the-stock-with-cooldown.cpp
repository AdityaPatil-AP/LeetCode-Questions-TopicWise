#include <bits/stdc++.h>
class Solution
{
public:
    int f(int ind, int buy, vector<int> &prices, vector<vector<int>> &dp)
    {
        // Base Case
        int n = prices.size();
        if (ind == n || ind == n + 1)
        {
            return 0;
        }
        if (dp[ind][buy] != -1)
        {
            return dp[ind][buy];
        }
        // Explorations
        if (buy == 1)
        {
            return dp[ind][buy] = max(-prices[ind] + f(ind + 1, 0, prices, dp),
                                      f(ind + 1, 1, prices, dp));
        }
        else
        {
            return dp[ind][buy] = max(prices[ind] + f(ind + 2, 1, prices, dp),
                                      f(ind + 1, 0, prices, dp));
        }
    }

    int maxProfit(vector<int> &prices)
    {
        // Recursion and Memiosation
        // int n = prices.size();
        // vector<vector<int>> dp(n + 2, vector<int>(2, -1));
        // return f(0, 1, prices, dp);

        // Tabulation
        // int n = prices.size();
        // vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        // // Base Case
        // // As n and n + 1 are already intialised with 0 base case care taken off
        // for(int i = n - 1; i >= 0;i--){
        //     for(int buy = 0;buy <= 1;buy++){
        //         if(buy == 1){
        //             dp[i][buy] = max(-prices[i] + dp[i + 1][0],
        //                             dp[i + 1][1]);
        //         }
        //         else{
        //             dp[i][buy] = max(prices[i] + dp[i + 2][1],
        //                             dp[i + 1][0]);
        //         }
        //     }
        // }
        // return dp[0][1];

        // Space Optimisation
        int n = prices.size();
        vector<int> ahead1(2, 0), ahead2(2, 0), curr(2, 0);
        // Base Case
        // As n and n + 1 are already intialised with 0 base case care taken off
        for (int i = n - 1; i >= 0; i--)
        {

            curr[1] = max(-prices[i] + ahead1[0],
                          ahead1[1]);

            curr[0] = max(prices[i] + ahead2[1],
                          ahead1[0]);

            ahead2 = ahead1;
            ahead1 = curr;
        }
        return ahead1[1];
    }
};
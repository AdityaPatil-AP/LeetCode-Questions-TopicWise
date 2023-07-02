class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        // profit.

        //         int profit = 0;
        //         memset(dp, -1, sizeof(dp));
        //         int ans = helper(0, prices, fee, 0);

        //         return ans;

        // Better way of approaching this type of Problems.

        // We have to find the Maximum Profit after n days.

        // So on a particular ith, we have three operations.
        // 1) Sell the stock on day ith.
        // 2) Buy the Stock on day ith.
        // 3) Do Nothing.

        // Assume we have computed the maximum profit for the first (i - 1) days.
        // dp[i] -> represents the maximum profit after first i days.

        // The question tells us, if we want to sell the stock, we must buy a stock.
        // We may have two different states at day ith.
        // 1) Currently holding the stock.
        // 2) Not currently holding the stock.

        // So our transition equation did not have two states to present.

        // 1) Maximum Profit when holding a stock.
        // 2) Maximum Profit when free of stock.

        // two arrays : - 1) free 2) hold.

        // Transition equations :

        // free[i] = max(free[i - 1], hold[i - 1] + prices[i] - fee);
        // hold[i] = max(hold[i - 1], free[i - 1] - prices[i]);
        int n = prices.size();
        int dp[n][2];

        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for (int i = 1; i < n; i++)
        {
            // Update the free state.
            // 1) Do Nothing.
            // 2) Sell the stock on ith day.
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);

            // Updating the holding state.
            // 1) Do Nothing.
            // 2) Buy the stock on ith day.
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }

        // There is no point holding the stock on the last day.
        // So our answer is free[n - 1]. -> dp[n - 1][0].
        return dp[n - 1][0];
    }

    //     int helper(int index, vector<int> &prices, int fee, int prev){
    //         int n = prices.size();

    //         // If there is nothing to buy as it is the end of the array.
    //         if(index == n){
    //             return 0;
    //         }

    //         if(dp[index][prev] != -1){
    //             return dp[index][prev];
    //         }

    //         // prev -> denotes the index of the stock we bought.
    //         int profit = 0;
    //         if(prev == 0){
    //             // buy the current stock.
    //             profit = max(profit, helper(index + 1, prices, fee, index + 1));

    //             // don't buy the current stock.
    //             profit = max(profit, helper(index + 1, prices, fee, prev));
    //         }

    //         else{
    //             // Sell the stock.
    //             profit = max(profit, helper(index + 1, prices, fee, 0) + (prices[index] - fee - prices[prev - 1]));

    //             // don't sell the stock.
    //             profit = max(profit, helper(index + 1, prices, fee, prev));
    //         }

    //         return dp[index][prev] = profit;
    //     }
};
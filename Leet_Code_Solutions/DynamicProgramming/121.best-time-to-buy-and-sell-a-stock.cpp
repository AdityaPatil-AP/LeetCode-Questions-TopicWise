class Solution
{
public:
    // 1) Kadane's Algorithm
    // int maxProfit(vector<int>& prices) {
    //     int profit = 0;
    //     int minelem = prices[0];
    //     for(int i = 1; i < prices.size();i++){
    //         minelem = min(minelem, prices[i]);
    //         profit = max(profit, (prices[i] - minelem));
    //     }
    //     return profit;
    // }
    // 2) 2nd Approach

    int maxProfit(vector<int> &prices)
    {
        //         int profit = 0;
        //         int minelem = prices[0];
        //         for(int i = 1;i < prices.size();i++){
        //             minelem = min(minelem, prices[i]);
        //             profit = max(profit, (prices[i] - minelem));
        //         }

        //         return profit;

        int minelem = prices[0];
        int profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            profit = max(profit, prices[i] - minelem);
            minelem = min(prices[i], minelem);
        }

        return profit;
    }
};
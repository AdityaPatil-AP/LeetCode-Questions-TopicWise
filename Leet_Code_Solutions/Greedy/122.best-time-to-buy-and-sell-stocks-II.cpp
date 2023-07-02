class Solution {
public:
    // Recursive Approach.
    int solve(vector<int>&prices, int index){
        if(index >= prices.size()){
            return 0;
        }
        
        int max = 0;
        for(int i = index;i < prices.size();i++){
            int maxprofit = 0;
            for(int j = i + 1;j < prices.size();j++){
                if(prices[i] < prices[j]){
                    int profit = solve(prices, j + 1) + (prices[j] - prices[i]);
                    if(profit > maxprofit)
                        maxprofit = profit;
                }
            }
            if(maxprofit > max){
                max = maxprofit;
            }
        }
        return max;
    }
    
    int maxProfit(vector<int>& prices) {
        // We are passing the start index and the prices array.
        // return solve(prices, 0);
        
        // 2. Peak Valley Approach(Greedy)...
        // We can see the points of interest are the consecutive valleys and peaks.
        // Total Profit = summation(height(peaki) - height(valleyi));
        // The key point is to consider every peak immediately after following a valley to maximise the profit.
        // A + B > C
        // int i = 0;
        // int valley = prices[0];
        // int peak = prices[0];
        // int maxprofit = 0;
        // while(i < prices.size() - 1){
        //     while(i < prices.size() - 1 && prices[i] >= prices[i + 1]){
        //         i++;
        //     }
        //     valley = prices[i];
        //     while(i < prices.size() - 1 && prices[i] <= prices[i + 1]){
        //         i++;
        //     }
        //     peak = prices[i];
        //     maxprofit += peak - valley;
        // }
        // return maxprofit;
        
        
         // Simple One Pass..
        int maxprofit = 0;
        for(int i = 1;i < prices.size();i++){
            if(prices[i] > prices[i - 1]){
                maxprofit += prices[i] - prices[i - 1];
            }
        }
        return maxprofit;
    }
};
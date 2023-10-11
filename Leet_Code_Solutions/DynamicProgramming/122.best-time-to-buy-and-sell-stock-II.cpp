class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {

        int n = prices.size();
        // vector<int> dp(n, 0);
        // dp[0] = 0;

        // for(int i = 1;i < n;i++){
        //     for(int j = i - 1;j >= 0;j--){
        //         if(prices[i] > prices[j]){
        //             dp[i] = max({dp[i], dp[j] + (prices[i] - prices[j])});
        //         }
        //         else{
        //             dp[i] = max(dp[i], dp[j]);
        //         }
        //     }
        // }

        // return dp[n - 1];
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            if (prices[i] > prices[i - 1])
            {
                ans += (prices[i] - prices[i - 1]);
            }
        }

        return ans;
    }
};
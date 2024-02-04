class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        int dp[n];

        memset(dp, -1, sizeof(dp));

        return maxSum(arr, k, dp, 0);
    }

    int maxSum(vector<int> &arr, int k, int dp[], int start){
        int n = arr.size();

        if(start >= n){
            return 0;
        }

        if(dp[start] != -1){
            return dp[start];
        }

        int ans = 0;
        int currMax = arr[start];
        for(int i = start;i < min(n, start + k);i++){
            currMax = max(currMax, arr[i]);

            ans = max(ans, (i - start + 1) * currMax + maxSum(arr, k, dp, i + 1));
        }

        return dp[start] = ans;
    }
};
class Solution
{
public:
    int solve(int n, int *dp)
    {
        if (n == 0)
        {
            return 0;
        }
        if (n == 1 || n == 2)
        {
            return 1;
        }
        if (dp[n] != 0)
        {
            return dp[n];
        }
        int ans = solve(n - 1, dp) + solve(n - 2, dp) + solve(n - 3, dp);
        return dp[n] = ans;
    }

    int tribonacci(int n)
    {
        // Recursion and time limit exceeded.
        // if(n == 0){
        //     return 0;
        // }
        // if(n == 1 || n == 2){
        //     return 1;
        // }
        // return tribonacci(n-1) + tribonacci(n - 2) + tribonacci(n - 3);
        // Recursion and Memoization
        // int dp[n + 1];
        // memset(dp, 0, sizeof(dp));
        // int ans = solve(n, dp);
        // return ans;

        // Tabulation Format
        // int dp[n + 1];
        // memset(dp, 0, sizeof(dp));
        // dp[0] = 0;
        // if(n >= 1)
        //     dp[1] = 1;
        // if(n >= 2)
        //     dp[2] = 1;
        // for(int i = 3;i <= n;i++){
        //     dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        // }
        // return dp[n];

        // Three variables approach
        // if(n == 0){
        //     return 0;
        // }
        // if(n == 1 || n == 2){
        //     return 1;
        // }
        // int prev1, prev2, prev3, curr;
        // prev1 = 1;
        // prev2 = 1;
        // prev3 = 0;
        // for(int i = 3;i <= n;i++){
        //     curr = prev1 + prev2 + prev3;
        //     prev3 = prev2;
        //     prev2 = prev1;
        //     prev1 = curr;
        // }
        // return curr;

        // Dp based solution.
        // vector<int> dp(n + 1, 0);
        // dp[0] = 0;
        // if(n >= 1)
        //     dp[1] = 1;
        // if(n >= 2)
        //     dp[2] = 1;
        // for(int i = 3;i <= n;i++){
        //     dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        // }
        // return dp[n];

        // Practice.
        if (n <= 1)
        {
            return n;
        }

        vector<int> dp(n + 1, 0);

        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }

        return dp[n];
    }
};
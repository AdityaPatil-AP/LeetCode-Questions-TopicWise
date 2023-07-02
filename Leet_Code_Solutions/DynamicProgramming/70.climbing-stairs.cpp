class Solution
{
public:
    // Recursive Approach
    // int numWays(int n, int *dp){
    //     if(n == 0){
    //         return 1;
    //     }
    //     if(n == 1){
    //         return 1;
    //     }
    //     if(dp[n] > 0){
    //         return dp[n];
    //     }
    //     int count1 = numWays(n - 1, dp);
    //     int count2 = numWays(n - 2, dp);
    //     dp[n] = count1 + count2;
    //     return count1 + count2;
    // }

    // Recursive Approach - Practice.
    int numWays(int n, vector<int> &dp)
    {
        if (n == 0)
            return 1;

        if (n == 1)
            return 1;
        if (dp[n] != -1)
            return dp[n];
        // I will take one Step..
        int count1 = numWays(n - 1, dp);
        // I will take 2 steps..
        int count2 = numWays(n - 2, dp);

        return dp[n] = count1 + count2;
    }

    int climbStairs(int n)
    {
        // Recursive Approach + memoization
        // int *dp = new int[n + 1]{};
        // int count = numWays(n, dp);
        // return count;
        // int *dp = new int[n + 1];
        // dp[0] = 1;
        // dp[1] = 1;
        // for(int i = 2;i <= n;i++){
        //     dp[i] = dp[i - 1] + dp[i - 2];
        // }
        // return dp[n];
        // or
        // int prev1 = 1;
        // int prev2 = 1;
        // int curr = prev1;
        // for(int i = 2;i <= n;i++){
        //     curr = prev1 + prev2;
        //     prev2 = prev1;
        //     prev1 = curr;
        // }
        // return curr;

        // Recursive Approach - gave a TLE
        // Why ??  Because for every step we had two choices therefore the time complexity reached.
        // O(2^n) - Exponential.
        // How to optimise this- If we see recursion tree. we can observe that we are making repetitive calls.
        // If we store them somewhere and then use them whenever needed will reducing the number of recursion calls.
        // Using memoisation.
        // vector<int> dp(n + 1, -1);
        // return numWays(n, dp);

        // Without Recursion.
        // vector<int> dp(n + 1, 0);
        // dp[0] = 1;
        // dp[1] = 1;
        // for(int i = 2;i <= n;i++){
        //     dp[i] = dp[i - 1] + dp[i - 2];
        // }
        // return dp[n];

        // Space Optimisation - We can see that at any instant we only require previous two values.
        // int prev1 = 1;
        // int prev2 = 1;
        // int curr = prev1;
        // for(int i = 2;i <= n;i++){
        //     curr = prev1 + prev2;
        //     prev2 = prev1;
        //     prev1 = curr;
        // }
        // return curr;

        if (n <= 1)
        {
            return 1;
        }

        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};
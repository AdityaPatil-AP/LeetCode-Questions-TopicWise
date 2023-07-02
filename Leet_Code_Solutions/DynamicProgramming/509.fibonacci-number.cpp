class Solution
{
public:
    int fib(int n)
    {
        if (n <= 1)
        {
            return n;
        }
        // return fib(n-1) + fib(n - 2);

        // vector<int> dp(n + 1, 0);
        // if(n >= 0) dp[0] = 0;
        // if(n >= 1) dp[1] = 1;
        int a = 0, b = 1;
        int c;
        for (int i = 2; i <= n; i++)
        {
            // dp[i] = dp[i - 1] + dp[i - 2];
            c = a + b;
            a = b;
            b = c;
        }

        return c;
    }
};
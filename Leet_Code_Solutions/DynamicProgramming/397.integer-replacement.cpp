class Solution
{
public:
    unordered_map<long long, long long> dp;
    int integerReplacement(int n)
    {
        dp[1] = 0;
        return finder(n);
    }

    int finder(long long n)
    {
        if (n == 1)
        {
            return 0;
        }

        // if(n >= INT_MAX){
        //     return 32;
        // }

        if (dp.find(n) != dp.end())
            return dp[n];

        if (n % 2 == 0)
            return dp[n] = 1 + finder(n / 2);
        return dp[n] = min(1 + finder(n + 1), 1 + finder(n - 1));
    }
};
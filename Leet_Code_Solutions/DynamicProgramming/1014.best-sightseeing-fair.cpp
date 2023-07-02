class Solution
{
public:
    int maxScoreSightseeingPair(vector<int> &values)
    {
        // Brute Force.
        //         int ans = 0;
        //         int n = values.size();

        //         for(int i = 0;i < n;i++){
        //             for(int j = i + 1;j < n;j++){
        //                 int curr = values[i] + values[j] + (i - j);
        //                 ans = max(ans, curr);
        //             }
        //         }

        //         return ans;

        // 2) Using Suffix Array.
        //         int n = values.size();
        //         vector<int> v = values, v1 = values;
        //         for(int i = 0;i < n;i++){
        //             v[i] += i;
        //             v1[i] -= i;
        //         }

        //         vector<int> suffSum(n);
        //         suffSum[n - 1] = v1[n - 1];
        //         for(int i = n - 2;i >= 0;i--) suffSum[i] = max(suffSum[i + 1], v1[i]);

        //         int ans = INT_MIN;

        //         for(int i = 0;i < n - 1;i++){
        //             ans = max(ans, v[i] + suffSum[i + 1]);
        //         }

        //         return ans;

        // 3) Using Recursion and Memoisation.
        // vector<vector<int>> dp(n, vector<int>(3, - 1));
        // return solve(0, 0, values, dp);

        // 4) Iterative dp way.
        // Using same concept as Buy and sell a stock.
        int n = values.size();
        int prevmaxi = values[0] + 0;
        int ans = -1e9;

        for (int i = 1; i < n; i++)
        {
            int curr = prevmaxi + values[i] - i;
            ans = max(curr, ans);
            prevmaxi = max(prevmaxi, values[i] + i);
        }

        return ans;
    }

    int solve(int index, int taken, vector<int> &values, vector<vector<int>> &dp)
    {
        int n = values.size();

        if (taken >= 2)
            return 0;
        if (index >= n)
            return -1e7; // Because all values are exhausted and we haven't picked
        // two values, so this can't be our answer.

        if (dp[index][taken] != -1)
        {
            return dp[index][taken];
        }

        // Now as we have to pick a pair and we haven't then, we are going to pick,
        // So we can pick this ith index element.
        int pick = values[index] + solve(index + 1, taken + 1, values, dp);

        // Or choose not to pick this ith index element.
        int notpick = solve(index + 1, taken, values, dp);

        if (taken == 1)
        {
            pick -= index;
        }
        else
        {
            pick += index;
        }

        return dp[index][taken] = max(pick, notpick);
    }
};
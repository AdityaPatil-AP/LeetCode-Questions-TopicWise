class Solution
{
public:
    // int dp[21][1001][1001];
    // int answer = 0;

    //     int helper(int index, int sum1, int sum2, vector<int> &rods){
    //         if(index == rods.size()){
    //             if(sum1 == sum2){
    //                 answer = max(answer, sum1);
    //                 return sum1;
    //             }
    //             return 0;
    //         }

    //         if(dp[index][sum1][sum2] != -1){
    //             return dp[index][sum1][sum2];
    //         }

    //         // There are three possibilites.
    //         // 1) Either this rod can be welded with the First Support.
    //         // 2) or With the 2nd Support.
    //         // 3) or Skipped.
    //         int ans = helper(index + 1, sum1 + rods[index], sum2, rods);

    //         ans = max(ans, helper(index + 1, sum1, sum2 + rods[index], rods));

    //         ans = max(ans, helper(index + 1, sum1, sum2, rods));

    //         return dp[index][sum1][sum2] = ans;

    //     }

    int tallestBillboard(vector<int> &rods)
    {
        // Time and space complexity Exceeding.
        //         memset(dp, -1, sizeof(dp));

        //         helper(0, 0, 0, rods);

        //         return answer;

        // Key Idea ->

        // 1) Using Difference.

        // -> Think of difference.

        // -> dp[d] -> maximum pair of sum we can get with pair difference d.

        // dp[diff] = b,

        // Here we have a pair of (b, b + diff) and that is the biggest pair with difference diff.

        // There are three cases.

        // 1) When we add current stick to the taller one.
        // 2) When we add it to the shorter one.
        // 3) Don't add it.
        int n = rods.size();
        unordered_map<int, int> dp;

        dp[0] = 0;

        for (auto x : rods)
        {
            unordered_map<int, int> cur(dp);
            for (auto it : cur)
            {
                int d = it.first;
                dp[d + x] = max(dp[d + x], cur[d]);
                dp[abs(d - x)] = max(dp[abs(d - x)], cur[d] + min(d, x));
            }
        }

        return dp[0];
    }
};
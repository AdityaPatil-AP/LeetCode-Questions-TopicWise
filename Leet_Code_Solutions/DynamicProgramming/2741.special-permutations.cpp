class Solution
{
public:
    // Before contest.
    // int mod = 1e9 + 7;
    // int dp[15][15][20000];

    //      int countPermutations(int index, int prevIndex, vector<int> &nums, int mask){
    //         if(index == (nums.size())){
    //             return 1;
    //         }

    //         if(dp[index][prevIndex][mask] != -1){
    //             return dp[index][prevIndex][mask];
    //         }

    //         long long ans = 0;
    //         int n = nums.size();

    //         for(int i = 0;i < 14 && i < nums.size();i++){
    //             if((mask>>i)&1){
    //                 continue;
    //             }

    //             if(prevIndex == 0){
    //                 int new_mask = (mask | (1 << i));
    //                 ans = (ans + countPermutations(index + 1, i + 1, nums, new_mask)) % mod;
    //             }
    //             else{
    //                 int prevVal = nums[prevIndex - 1];
    //                 int currVal = nums[i];
    //                 int new_mask = (mask | (1 << (i)));
    //                 if((prevVal % currVal == 0) || (currVal % prevVal == 0)){
    //                     ans = (ans + countPermutations(index + 1, i + 1, nums, new_mask)) % mod;
    //                 }
    //             }
    //         }

    //         return dp[index][prevIndex][mask] = ans % mod;
    //     }

    // After Contest.
    // We only needed two parameters. First one is prevIndex used and second one is mask for tracking
    // the elements used.
    int dp[14][16383];
    const int mod = 1e9 + 7;

    int dfs(int i, int mask, vector<int> &nums)
    {
        if (mask == ((1 << nums.size()) - 1))
        {
            return 1;
        }

        if (dp[i][mask] == -1)
        {
            dp[i][mask] = 0;

            for (int j = 0; j < nums.size(); j++)
            {
                if ((mask & (1 << j)) == 0)
                {
                    if (mask == 0 || (nums[j] % nums[i] == 0) || (nums[i] % nums[j] == 0))
                    {
                        dp[i][mask] = (dp[i][mask] + dfs(j, (mask | (1 << j)), nums)) % mod;
                    }
                }
            }
        }

        return dp[i][mask];
    }

    int specialPerm(vector<int> &nums)
    {
        // My Answer during Contest using DP + Bitmask.
        //         int n = nums.size();

        //         memset(dp, -1, sizeof(dp));
        //         int count = countPermutations(0, 0, nums, 0);

        //         return count % mod;

        // After Contest.
        memset(dp, -1, sizeof(dp));
        int count = dfs(0, 0, nums);

        return count;
    }
};
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        //         int n = nums.size();
        //        int minSteps = 1e8;
        //         vector<int> dp(n + 1,1e8);
        //         dp[0] = 0;
        //         for(int i = 1;i < n;i++){
        //             for(int j = i - 1;j >= 0;j--){
        //                 if((j + nums[j]) >= i){
        //                     dp[i] = min(dp[i], dp[j] + 1);
        //                 }
        //             }
        //         }

        //         return dp[n - 1];

        // The starting range of the first jump is [0, 0].
        int answer = 0, n = (int)nums.size();

        int currEnd = 0, currFar = 0;

        for (int i = 0; i < n - 1; i++)
        {
            // Update the farthest reachable index of this jump.

            currFar = max(currFar, i + nums[i]);

            if (i == currEnd)
            {
                currEnd = currFar;
                answer++;
            }
        }

        return answer;
    }
};
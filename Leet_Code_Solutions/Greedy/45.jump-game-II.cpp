class Solution
{
public:
    int solve(int i, vector<int> &nums, vector<int> &dp)
    {
        if (i == (nums.size() - 1))
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }
        int reachable = nums[i] + i;
        int steps = 1e8;
        for (int k = i + 1; k < nums.size() && k <= reachable; k++)
        {
            steps = min(steps, 1 + solve(k, nums, dp));
        }
        return dp[i] = steps;
    }

    int jump(vector<int> &nums)
    {
        // Recursion.
        // Memoization..
        // vector<int> dp(nums.size(), -1);
        // return solve(0, nums, dp);

        // Greedy - Using reachability Concept.
        // currjump - denoting the jump we took from the previous position.
        // maxjump - denoting the maximum jump we can take from the positions ahead.
        // jump - to count the number of jumps.
        // if(nums.size() < 2){
        //     return 0;
        // }
        // int jump = 0, maxjump = 0, currjump = 0;
        // int i = 0; // The current position we are at.
        // int n = nums.size();
        // while(i < n - 1){
        //     maxjump = max(maxjump, i + nums[i]);
        //     if(currjump == i){
        //         jump++;
        //         currjump = maxjump;
        //     }
        //     i++;
        // }
        // return jump;

        // Greedy Approach.

        // the starting range of the first jump is [0, 0].
        int answer = 0, n = int(nums.size());

        int curEnd = 0, curFar = 0;

        for (int i = 0; i < n - 1; i++)
        {
            // Update the farthest reachable index of this jump.
            curFar = max(curFar, i + nums[i]);

            // If we finish the starting range of this jump,
            // Move on to the starting range of the next jump,

            if (i == curEnd)
            {
                answer++;
                curEnd = curFar;
            }
        }

        return answer;
    }
};
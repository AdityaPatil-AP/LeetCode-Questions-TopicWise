class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        // Minimum Size Subarray Sum.
        // Using Sliding Window.

        int total_sum = accumulate(begin(nums), end(nums), 0);
        if (total_sum < target)
            return 0;

        int n = nums.size();
        int j = 0; // to define the boundaries of the subarray.
        int sum = 0;
        int ans = n;
        for (int i = 0; i < nums.size(); i++)
        {
            while (j < n && sum < target)
            {
                sum += nums[j];
                j++;
            }

            if (sum >= target)
                ans = min(ans, (j - i));
            sum -= nums[i];
        }

        return ans;

        // 2) Approach - Could be Solved Using Binary Search and Prefix Sum.

        // int ans = INT_MAX;

        // // we will try to create such a favorable window.
        // int i = 0, j = 0;
        // int sum = 0;

        // while(j < nums.size()){
        //     sum += nums[j];

        //     if(sum >= target){
        //         while(sum >= target){
        //             ans = min(ans, (j - i + 1));
        //             sum -= nums[i];
        //             i++;
        //         }
        //     }

        //     j++;
        // }

        // if(ans == INT_MAX) return 0;

        // return ans;
    }
};
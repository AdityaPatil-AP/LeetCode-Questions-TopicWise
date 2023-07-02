

class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {

        //         // 1) Enumerate Prefix and Suffix Sums.
        //         // If the subarray is circular,
        //         // Then the two factors contributing to it would be,
        //         // 1) The summation of maximum prefix sum and maximum suffix sum of the array.
        //         // or 2) Maximum sum subarray.

        //         // 1) max(prefix sum(i) + suffix sum(i)) will be our answer.

        //         int n = nums.size();
        //         vector<int> rightMax(n);

        //         rightMax[n - 1] = nums[n - 1];
        //         for(int suffix_sum = nums[n - 1], i = n - 2;i >= 0;i--){
        //             suffix_sum += nums[i];
        //             rightMax[i] = max(rightMax[i + 1], suffix_sum);
        //         }

        //         // Now we have calculated rightMax.
        //         // Let's enumerate over all the prefixes, and find the special sum
        //         // whilst also find normal sum(MSS).
        //         int max_sum = nums[0];
        //         int special_sum = nums[0];
        //         for(int i = 0, prefix_sum = 0, currMax = 0;i < n;i++){
        //             currMax = max(currMax, 0) + nums[i];
        //             // Kadane's Algorithm.
        //             max_sum = max(max_sum, currMax);

        //             prefix_sum += nums[i];

        //             if(i + 1 < n){
        //                 special_sum = max(special_sum, prefix_sum + rightMax[i + 1]);
        //             }
        //         }
        //         return max(max_sum, special_sum);

        // 2) Calculate the "Minimum Subarray".
        int sum = 0, currMax = 0, currMin = 0, max_sum = nums[0], min_sum = nums[0];

        for (auto num : nums)
        {
            // for maximum sum subarray.
            currMax = max(currMax, 0) + num;
            max_sum = max(max_sum, currMax);

            // for minimum sum subarray.
            currMin = min(currMin, 0) + num;
            min_sum = min(min_sum, currMin);

            sum += num;
        }

        // When all numbers are negative, then the special sum will be 0, therefore in
        // that case our answer is minimum negative element, which is present in max_sum.
        // So when (sum == min_sum). then return max_sum for true case.
        // or else maximum(normal_sum, special_sum).
        return (sum == min_sum) ? max_sum : max(max_sum, sum - min_sum);
    }
};
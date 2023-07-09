class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        // TLE
        // int max_sum = INT_MIN;
        // for(int i = 0; i < nums.size(); i++){
        //     int currsum = 0;
        //     for(int j = i; j < nums.size();j++){
        //         currsum += nums[j];
        //         max_sum = max(max_sum, currsum);
        //     }
        // }
        // return max_sum;

        // Kadane's Algorithm
        // int Max = INT_MIN;
        // int sum = 0;
        // int n = nums.size();
        // for(int i = 0; i < n; i++){
        //     sum += nums[i];
        //     Max = max(sum,Max);
        //     if(sum < 0)
        //         sum = 0;
        // }
        // return Max;

        // This Question can be done using Maximum sum subarray.
        // In this we always take in account till we are positive we can always
        // take the prev_sum. Otherwise start a new subarray from the Current Position.

        int local_max = 0;
        int global_max = -1e4;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            local_max += (nums[i]);

            global_max = max(global_max, local_max);

            if (local_max < 0)
            {
                local_max = 0;
            }
        }

        return global_max;
    }
};
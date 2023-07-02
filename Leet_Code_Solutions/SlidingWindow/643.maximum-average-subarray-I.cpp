class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // array + subarray + a window size is given(K)
        // Fixed sliding window question..
        // We have to find and return the largest average value among all the subarrays.
        int i = 0, j = 0;
        double average = INT_MIN;
        double sum = 0;
        while(j < nums.size()){
            // Calculations
            sum += nums[j];
            if((j - i + 1) < k){
                j++;
            }
            else if((j - i + 1) == k){
                // ans <- calculations.
                if((sum/k) > average){
                    average = sum/k;
                }
                // Sliding the window
                // 1) remove calculations for i..
                sum -= nums[i];
                // 2) Maintain the size of the window.
                i++,j++;
            }
        }
        return average;
    }
};
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k == 1) return 0;
        sort(nums.begin(), nums.end());
        int i = 0, j = 0; //creation of the window..
        int minans = INT_MAX;
        while(j < nums.size()){
            // Calcuations
            if((j - i + 1) < k) j++;
            if((j - i + 1) == k){
                // ans <- calculations
                minans = min(minans, nums[j] - nums[i]);
                // Sliding the window
                // Remove calculations for i.
                i++, j++; // Maintain the size of the window.
            }
        }
        return minans;
    }
};
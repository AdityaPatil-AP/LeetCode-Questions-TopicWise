class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        // Three pointers and variable sliding window.
        long long ans = 0;
        long jmin = -1, jmax = -1, jbad = -1;
        int n = nums.size();
        for(int i = 0;i < n;i++){
            if(nums[i] < minK || nums[i] > maxK){
                jbad = i;
            }
            if(nums[i] == minK) jmin = i;
            if(nums[i] == maxK) jmax = i;
            
            ans += max(0L, min(jmin, jmax) - jbad);
        }
        
        return ans;
    }
};
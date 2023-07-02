class Solution {
public:
    int search(vector<int>& nums, int target) {
        int high = nums.size() - 1, low = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                low++;
            }
            else{
                high--;
            }
        }
        return -1;
    }
};
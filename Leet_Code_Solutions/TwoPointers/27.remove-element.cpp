class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = nums.size() - 1;
        while(i <= j){
            while(i <= j && nums[j] == val){
                j--;
            }
            while(i <= j && nums[i] != val){
                i++;
            }
            if(i < j){
                swap(nums[i], nums[j]);
            }
            else break;
        }
        return j + 1;
    }
};
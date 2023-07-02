class Solution {
public:
    // Using Two Pointer Approach as the array is sorted
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0, high = numbers.size() - 1;
        vector<int> ans;
        while(low < high){
            int sum = numbers[low] + numbers[high];
            if(sum > target){
                high--;
            }
            else if(sum < target){
                low++;
            }
            else{
                ans.push_back(low + 1);
                ans.push_back(high + 1);
                break;
            }
        }
        return ans;
    }
};
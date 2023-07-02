class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int maxi = -1;
        // edge case is when we have one element and when we remove it no element is there in the array.
        if(nums.size() == 1 && k % 2 == 1){
            return -1;
        }
        // 1) I can at max remove k - 1 elements and then push max among them at the kth move.
        
        // 2) Or I can remove all k elements and check for the largest at the k + 1 position.
        
        // According to this our answer can be k - 1 elements of k + 1th elements.
        for(int i = 0;i < k - 1 && i < nums.size();i++){
            maxi = max(maxi, nums[i]);
        }
        // or the k + 1 element which is the kth index.
        if(k < nums.size()){
            maxi = max(maxi, nums[k]);
        }
        return maxi;
    }
};
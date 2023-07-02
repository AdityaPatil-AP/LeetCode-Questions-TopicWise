class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // // array + subarray + condition = all k odd numbers in the subarray of any size.
        // // This is a variable sliding window questions.
        // // ans indicates the number of such subarrays of size k with all odd numbers.
        // int ans = 0;
        // int i = 0, j = 0;// Creation of the window.
        // int count = 0; // denotes the number of odd elements in the current window.
        // while(j < nums.size()){
        //     // calculations - if current number is odd, then we increment the count.
        //     if(nums[j] % 2 == 1) count++;
        //     // We require exactly k odd numbers so we will increment the count.
        //     if(count < k){
        //         j++;
        //     }
        //     else if(count == k){
        //         // ans<-calculations
        //         // if the count of odd numbers is k, then we find that this window is the possible answer.
        //         // then we increase the size of the window to check if the next window that is (i, j+1) is
        //         // also having k odd numbers or not.
        //         while(count == k){
        //             if(nums[i] % 2 == 1){
        //                 count--;
        //             }
        //             ans++;
        //             i++;
        //         }
        //         j++;
        //     }
        // }
        // if(count == k){
        //     ans++;
        // }
        // return ans;
        
        // Tentative Approach Explained
        int j = 0, count = 0, total = 0, odd = 0;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] & 1){
                odd++;
                if(odd >= k){
                    count = 1;
                    while(!(nums[j++] & 1)) count++;
                    total += count;
                }
            }
            else if(odd >= k) total += count;
        }
        return total;
    }
};
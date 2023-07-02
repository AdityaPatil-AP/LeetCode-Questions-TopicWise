#define ll long long int
class Solution {
public:
    // Iterative Approach for 4Sum.
    // In generalisation for kSum problem, we can have (k - 2 nested loops) and then in sorted array 
    // we implementing the two pointer appraoch.
    // vector<vector<int>> fourSum(vector<int>& nums, int target) {
    //     if(nums.size() < 4) return {};
    //     sort(nums.begin(),nums.end());
    //     vector<vector<int>> ans;
    //     int n = nums.size();
    //     for(int i = 0;i < n - 3;i++){
    //         /* Conditions for pruning */
    //         if(target <= 0 && nums[i] > 0) break;
    //         // if nums[i] has become too large.. no point in continuing
    //         if((ll)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
    //         // if nums[i] is very small that the largest numbers also can't help to reach the sum.
    //         if((ll)nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) continue;
    //         // newtarget
    //         ll newtarget = target - nums[i];
    //         // skip duplicates.
    //         if(i > 0 && nums[i] == nums[i-1]){
    //             continue;
    //         }
    //         for(int j = i + 1;j < n - 2;j++){
    //             /* Conditions for pruning */
    //             // if nums[j] is small that even the largest numbers are not helping to reach the sum.
    //             if((ll)nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target) continue;
    //             // if nums[j] has become too large, then there is no point in continuing.
    //             if((ll)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
    //             // skip duplicates
    //             if(j > i + 1 && nums[j] == nums[j - 1]){
    //                 continue;
    //             }
    //             // newtarget2
    //             ll newtarget2 = newtarget - nums[j];
    //             int low = j + 1, high = n - 1;
    //             while(low < high){
    //                 ll sum = nums[low] + nums[high];
    //                 if(sum < newtarget2){
    //                     low++;
    //                 }
    //                 else if(sum > newtarget2){
    //                     high--;
    //                 }
    //                 else{
    //                     ans.push_back({nums[i], nums[j], nums[low], nums[high]});
    //                     int lownumber = nums[low];
    //                     while(low < high && nums[low] == lownumber){
    //                         low++;
    //                     }
    //                     int highnumber = nums[high];
    //                     while(low < high && nums[high] == highnumber){
    //                         high--;
    //                     }
    //                 } 
    //             }
    //         }
    //     }
    // //     return ans;
    // }
    
    // Recursive Approach
    vector<vector<int>> fourSum(vector<int> &nums, int target){
        sort(nums.begin(),nums.end());
        // we need to pass the nums array, target, start and k;
        return kSum(nums, target, 0, 4);
    }
    
    vector<vector<int>> kSum(vector<int> &nums, long long target, int start, int k){
        vector<vector<int>> res;
        // To check have we ran out of the numbers
        if(start == nums.size()){
            return res;
        }
        // To check if we can actually achieve the target we find the average_value.
        long long average_value = target/k;
        
        // If the smallest number is greater than the average_value, or the largest number is lesser than the average_value
        // then in both the cases the we would not be able to achieve the target, so we need to return the res.
        if(nums[start] > average_value || average_value > nums.back()){
            return res;
        }
        
        if(k == 2){
            return twoSum(nums, target, start);
        }
        
        for(int i = start; i < nums.size();i++){
            if(i == start || nums[i - 1] != nums[i]){
                for(vector<int> &subset : kSum(nums, static_cast<long long>(target) - nums[i], i + 1, k - 1)){
                    res.push_back({nums[i]});
                    res.back().insert(res.back().end(), subset.begin(), subset.end());
                }
            }
        }
        return res;
    }
    
//     vector<vector<int>> twoSum(vector<int> &nums, long long target, int start){
//         vector<vector<int>> res;
//         int low = start, high = int(nums.size()) - 1;
//         while(low < high){
//             int sum = nums[low] + nums[high];
//             if(sum < target || (low > start && nums[low] == nums[low - 1])){
//                 low++;
//             }
//             else if(sum > target || (high < nums.size() - 1 && nums[high] == nums[high + 1])){
//                 high--;
//             }
//             else{
//                 res.push_back({nums[low], nums[high]});
//                 high--;
//                 low++;
//             }
//         }
//         return res;
//     }
    
    // Using Hash Set Implementation
    vector<vector<int>> twoSum(vector<int>&nums, long long target, int start){
        unordered_set<long long> s;
        vector<vector<int>> res;
        for(int i = start; i < nums.size();i++){
            if(res.empty() || res.back()[1] != nums[i]){
                if(s.count(target - nums[i])){
                    res.push_back({int(target - nums[i]), nums[i]});
                }
            }
            s.insert(nums[i]);
        }
        return res;
    }
};
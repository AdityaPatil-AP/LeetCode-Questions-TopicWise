class Solution
{
public:
    // Using unordered map
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     unordered_map<int, int> hash;
    //     vector<int> ans;
    //     for(int i = 0; i < nums.size(); i++){
    //         if(hash.count(target-nums[i])){
    //             ans.push_back(hash[target-nums[i]]);
    //             ans.push_back(i);
    //             return ans;
    //         }
    //         else{
    //             hash[nums[i]] = i;
    //         }
    //     }
    //     return ans;
    // }

    // vector<int> twoSum(vector<int>&nums, int target){
    //     unordered_map<int,int> umap;
    //     vector<int>ans;
    //     for(int i = 0;i<nums.size();i++){
    //         if(umap.count(target - nums[i])){
    //             ans.push_back(umap[target-nums[i]]);
    //             ans.push_back(i);
    //             return ans;
    //         }
    //         else{
    //             umap[nums[i]] = i;
    //         }
    //     }
    //     return ans;
    // }

    // Using two pointer and vector<pair<int,int>>, T>C> - O(nlogn).
    // vector<int>  twoSum(vector<int>&nums, int target){
    //     vector<pair<int,int>> pos;
    //     int n = nums.size();
    //     for(int i = 0;i < n;i++){
    //         pos.push_back({nums[i], i});
    //     }
    //     sort(pos.begin(), pos.end());
    //     int low = 0, high = n - 1;
    //     vector<int> ans;
    //     while(low < high){
    //         int sum = pos[low].first + pos[high].first;
    //         if(sum > target){
    //             high--;
    //         }
    //         else if(sum < target){
    //             low++;
    //         }
    //         else{
    //             ans.push_back(pos[low].second);
    //             ans.push_back(pos[high].second);
    //             break;
    //         }
    //     }
    //     return ans;
    // }

    // My attempts later on - For Practice
    // Using Hashmap..
    // vector<int> twoSum(vector<int> &nums, int target){
    //     unordered_map<int,int> mp;
    //     for(int i = 0;i < nums.size();i++){
    //         if(mp.find(target - nums[i]) != mp.end()){
    //             return {mp[target - nums[i]], i};
    //         }
    //         else {
    //             mp[nums[i]] = i;
    //         }
    //     }
    //     return {0, 0};
    // }

    // Using Two pointer approach..
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<pair<int, int>> pos(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            pos[i].first = nums[i];
            pos[i].second = i;
        }

        sort(pos.begin(), pos.end());

        int i = 0, j = nums.size() - 1;
        while (i < j)
        {
            if ((pos[i].first + pos[j].first) == target)
            {
                return {pos[i].second, pos[j].second};
            }
            else if ((pos[i].first + pos[j].first) < target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return {0, 0};
    }

    // O(n^2) time complexity if you use two for loops without sort function.
};
class Solution
{
public:
    // Gave a TLE because a O(n^3) approach
    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     // sort(nums.begin(), nums.end());
    //     vector<vector<int>> ans;
    //     sort(nums.begin(),nums.end());
    //     for(int i = 0;i < nums.size();i++){
    //         int target = (-nums[i]);
    //         for(int j = i + 1;j < nums.size();j++){
    //             int newtarget = (target - nums[j]);
    //             for(int k = j + 1;k < nums.size();k++){
    //                 if(newtarget == nums[k]){
    //                     vector<int> ans1;
    //                     ans1.push_back(nums[i]);
    //                     ans1.push_back(nums[j]);
    //                     ans1.push_back(nums[k]);
    //                     ans.push_back(ans1);
    //                 }
    //             }
    //         }
    //     }
    //     set<vector<int>> st(ans.begin(), ans.end());
    //     ans.clear();
    //     for(auto i : st){
    //         ans.push_back(i);
    //     }
    //     return ans;
    // }

    // According to constraints O(n^2) approach will work
    // For that we have to fix a number and then use the two - pointer approach after sorting the
    // array.
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 2; i++)
        {

            // if numbers is positive then no answers ahead.
            if (nums[i] > 0)
            {
                break;
            }

            // to check if the answer is already been computed the given number.
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            int low = i + 1, high = n - 1;
            while (low < high)
            {
                int sum = nums[i] + nums[low] + nums[high];
                if (sum > 0)
                    high--;
                else if (sum < 0)
                    low++;
                else
                {
                    ans.push_back({nums[low], nums[i], nums[high]});
                    int lownumber = nums[low];
                    while (low < high && nums[low] == lownumber)
                    {
                        low++;
                    }
                    int highnumber = nums[high];
                    while (low < high && nums[high] == highnumber)
                    {
                        high--;
                    }
                }
            }
        }
        return ans;
    }
};
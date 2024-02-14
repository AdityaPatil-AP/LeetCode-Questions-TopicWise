class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        // vector<int> negative, positive;
        // for(auto num : nums){
        //     if(num < 0) negative.push_back(num);
        //     else positive.push_back(num);
        // }

        // vector<int> ans;
        // for(int i = 0;i < positive.size();i++){
        //     ans.push_back(positive[i]);
        //     ans.push_back(negative[i]);
        // }

        // return ans;

        // In one pass.

        int positive = 0;
        int negative = 0;
        int n = nums.size();

        vector<int> ans;
        while (positive < n && negative < n)
        {
            while (positive < n && nums[positive] < 0)
            {
                positive++;
            }
            ans.push_back(nums[positive++]);
            while (negative < n && nums[negative] > 0)
            {
                negative++;
            }
            ans.push_back(nums[negative++]);
        }

        return ans;
    }
};
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int idx1 = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

        int idx2 = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        idx2--;

        if (idx1 < nums.size())
        {
            if (nums[idx1] == target)
            {
                return {idx1, idx2};
            }
            else
                return {-1, -1};
        }

        return {-1, -1};
    }
};
class Solution
{
public:
    int findValueOfPartition(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int minDiff = INT_MAX;

        for (int i = 1; i < n; i++)
        {
            minDiff = min(minDiff, nums[i] - nums[i - 1]);
        }

        return minDiff;
    }
};
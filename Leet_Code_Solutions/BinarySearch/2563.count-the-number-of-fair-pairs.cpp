class Solution
{
public:
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        long long ans = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int first = nums[i];
            // Secondlower >= lower - nums[i];
            int secondLower = lower - nums[i];
            // secondUpper <= upper - nums[i];
            int secondUpper = upper - nums[i];

            int idx1 = lower_bound(nums.begin(), nums.end(), secondLower) - nums.begin();
            int idx2 = upper_bound(nums.begin(), nums.end(), secondUpper) - nums.begin();

            if (idx1 <= i)
            {
                idx1 = i + 1;
            }
            if (idx2 >= idx1)
                ans += (idx2 - idx1);
        }

        return ans;
    }
};
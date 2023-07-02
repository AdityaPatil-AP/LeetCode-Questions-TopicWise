class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int ans = INT_MAX;

        // we will try to create such a favorable window.
        int i = 0, j = 0;
        int sum = 0;

        while (j < nums.size())
        {
            sum += nums[j];

            if (sum >= target)
            {
                while (sum >= target)
                {
                    ans = min(ans, (j - i + 1));
                    sum -= nums[i];
                    i++;
                }
            }

            j++;
        }

        if (ans == INT_MAX)
            return 0;

        return ans;
    }
};
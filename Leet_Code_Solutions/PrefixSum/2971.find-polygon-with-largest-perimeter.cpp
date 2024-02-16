class Solution
{
public:
    long long largestPerimeter(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<long long> ps(n, 0);
        ps[0] = nums[0];

        for (int i = 1; i < n; i++)
        {
            ps[i] = ps[i - 1] + nums[i];
        }

        long long ans = -1;

        for (int i = 2; i < n; i++)
        {
            if (ps[i - 1] > nums[i])
            {
                ans = ps[i - 1] + nums[i];
            }
        }

        return ans;
    }
};
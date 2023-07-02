class Solution
{
public:
    vector<int> getAverages(vector<int> &nums, int k)
    {
        // Prefix Sum.
        int n = nums.size();

        vector<long long> prefixSum(n + 1, 0);
        prefixSum[0] = nums[0];

        for (int i = 1; i < n; i++)
        {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        vector<int> avgs(n, -1);

        for (int i = k; i <= (n - k - 1); i++)
        {
            long long start = (i - k - 1) == -1 ? 0 : prefixSum[i - k - 1];
            long long end = prefixSum[i + k];

            long long ans = (end - start) / (2 * k + 1);

            avgs[i] = ans;
        }

        return avgs;
    }
};
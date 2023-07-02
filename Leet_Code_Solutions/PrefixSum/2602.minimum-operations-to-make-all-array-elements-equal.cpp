class Solution
{
public:
    vector<long long> minOperations(vector<int> &nums, vector<int> &queries)
    {
        // Using Prefix Sum + Binary Search + Sorting.

        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<long long> prefSum(n, 0);
        prefSum[0] = nums[0];

        for (int i = 1; i < n; i++)
        {
            prefSum[i] = prefSum[i - 1] + nums[i];
        }

        vector<long long> ans;

        for (auto query : queries)
        {
            int index = lower_bound(nums.begin(), nums.end(), query) - nums.begin();

            long long suffix = 0, prefix = 0;

            // finding suffix
            if (index < n)
            {
                suffix = (index == 0) ? prefSum[n - 1] : (prefSum[n - 1] - prefSum[index - 1]);

                suffix = suffix - ((long long)n - index) * query;
            }

            // Finding prefix.
            if (index - 1 >= 0)
            {
                prefix = ((long long)(index)*query);
                prefix = prefix - (prefSum[index - 1]);
            }

            ans.push_back((suffix + prefix));
        }

        return ans;
    }
};
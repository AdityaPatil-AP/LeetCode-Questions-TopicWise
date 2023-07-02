class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        // Here we use PrefixSum + HashTable.

        // Use Prefix Sum and Hash Table.
        int n = nums.size();

        int prefSum[n];

        prefSum[0] = nums[0];

        for (int i = 1; i < n; i++)
        {
            prefSum[i] = prefSum[i - 1] + nums[i];
        }

        int ans = 0;
        unordered_map<int, int> mp; // map to store the prefSum and their frequencies.

        for (int i = 0; i < n; i++)
        {

            if (prefSum[i] == k)
                ans++;

            if (mp.find(prefSum[i] - k) != mp.end())
            {
                ans += mp[prefSum[i] - k];
            }

            mp[prefSum[i]]++;
        }

        return ans;
    }
};
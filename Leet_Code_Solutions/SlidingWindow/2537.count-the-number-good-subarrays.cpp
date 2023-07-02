class Solution
{
public:
    long long countGood(vector<int> &nums, int k)
    {
        // Count the number of good subarrays.
        int i = 0, j = 0; // Denoting the start and the end of the subarray.
        long long ans = 0, c = 0;
        int n = nums.size();
        unordered_map<int, int> mp; // To check the frequency of the elements till now.
        while (j < n)
        {
            mp[nums[j]]++;
            c += (mp[nums[j]] - 1);
            while (i < j && c >= k)
            {
                ans += n - j;
                mp[nums[i]]--;
                c -= (mp[nums[i]]);
                i++;
            }
            j++;
        }
        return ans;
    }
};
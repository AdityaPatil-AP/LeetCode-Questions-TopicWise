class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        // Prefix Sum + Counting.
        // count of subarrays which are divisible by k.
        int i = 0, count = 0, prefixSum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        while (i < nums.size())
        {
            int rem = (((nums[i] + prefixSum) % k) + k) % k;
            count += mp[rem];
            mp[rem]++;
            prefixSum += nums[i];
            i++;
        }

        return count;
    }
};
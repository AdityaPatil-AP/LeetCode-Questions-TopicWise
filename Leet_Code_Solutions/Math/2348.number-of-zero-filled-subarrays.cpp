class Solution
{
public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        // Here we have to find the number of subarrays filled with only subarrays.

        long long ans = 0;
        int n = nums.size();

        int z = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                ans += ((long long)z * (z + 1)) / 2;
                z = 0;
            }
            else
            {
                z++;
            }
        }

        // If we get out of loop but still last subarray with all zeroes is remaining.
        ans += ((long long)z * (z + 1)) / 2;

        return ans;
    }
};
class Solution
{
public:
    int xorBeauty(vector<int> &nums)
    {
        // If we think the possible triplets that can be made.
        // there are basically three numbers, a, b, c.
        // And if we at the possible configurations.
        // which are. (a|b) & c or (b|a) & c they are both same therefore, they don't have any impact
        // on xor beauty. Therefore will only consider (a|a) & a kindof triplets which means the numbers
        // itself. So the final answer is the xor of array.
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ans ^= nums[i];
        }
        return ans;
    }
};
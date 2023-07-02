class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int pos = 0, cursor = 1;
        while (cursor < nums.size())
        {
            if (nums[pos] == nums[cursor])
            {
                cursor++;
            }
            else
            {
                nums[pos + 1] = nums[cursor];
                pos++, cursor++;
            }
        }
        return pos + 1;
    }
};
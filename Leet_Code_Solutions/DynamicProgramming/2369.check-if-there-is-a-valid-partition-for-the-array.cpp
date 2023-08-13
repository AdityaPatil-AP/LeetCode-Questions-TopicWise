class Solution
{
public:
    vector<int> dp;
    bool validPartition(vector<int> &nums)
    {
        // Checking for all the partitions.

        dp.assign(nums.size(), -1);

        // We can use a dp approach to try and find all the ways.
        if (isPossible(0, nums))
        {
            return true;
        }

        return false;
    }

    bool isPossible(int index, vector<int> &nums)
    {
        // if(index > nums.size()) return false;

        if (index == nums.size())
        {
            return true;
        }

        if (dp[index] != -1)
        {
            return dp[index];
        }

        // There are three ways to form subarrays for the partition.
        // 1) Check if first two elements are equal.
        bool part1 = false, part2 = false, part3 = false;
        if (index + 1 < nums.size())
        {
            if (nums[index] == nums[index + 1])
            {
                part1 = isPossible(index + 2, nums);
            }
        }

        // 2) Check if first three elements are equal.
        if (index + 2 < nums.size())
        {
            if (nums[index] == nums[index + 1] && nums[index] == nums[index + 2])
            {
                part2 = isPossible(index + 3, nums);
            }
        }

        // 3) Check if first three consecutive elements are present.
        if (index + 2 < nums.size())
        {
            if (nums[index] + 1 == nums[index + 1] && nums[index] + 2 == nums[index + 2])
            {
                part3 = isPossible(index + 3, nums);
            }
        }

        if (part1 || part2 || part3)
        {
            return dp[index] = true;
        }

        return dp[index] = false;
    }
};
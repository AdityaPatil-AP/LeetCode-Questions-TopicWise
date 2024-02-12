class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        // Using sort.
        // sort(nums.begin(), nums.end());

        // return nums[nums.size()/2];

        // Using Hashmap

        // In Linear time and O(1) space.
        // Using Boyer - Moore Voting Algorithm.
        // Here we know that the majority element exists, otherwise we have to
        // do the 2nd traversal to check if the current candidate is actually a majority element
        // or not.
        int count = 0;
        int candidate = -1;

        for (int num : nums)
        {
            if (count == 0)
            {
                candidate = num;
            }

            if (num == candidate)
            {
                count++;
            }
            else
            {
                count--;
            }
        }

        return candidate;
    }
};
class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        // Find the index where the Rotation is performed.
        int n = nums.size();
        int rotatedIndex = 0;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] < nums[i - 1])
            {
                rotatedIndex = i;
                break;
            }
        }

        // Searching using Binary Search for the target in
        // two Subdivisions, [0, rotatedIndex - 1] and [rotatedIndex, n - 1].

        bool search1 = isPresent(nums, target, 0, rotatedIndex - 1);
        bool search2 = isPresent(nums, target, rotatedIndex, n - 1);

        if (search1 || search2)
        {
            return true;
        }
        return false;
    }

    bool isPresent(vector<int> &nums, int target, int start, int end)
    {
        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target)
            {
                return true;
            }
            else if (nums[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return false;
    }
};
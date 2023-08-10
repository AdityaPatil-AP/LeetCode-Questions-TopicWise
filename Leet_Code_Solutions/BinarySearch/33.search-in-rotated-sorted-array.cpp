class Solution
{
public:
    bool existsInFirst(vector<int> &nums, int start, int element)
    {
        return nums[start] <= element;
    }

    int search(vector<int> &nums, int target)
    {
        // Editorial Approach.
        int n = nums.size();
        int end = n - 1;
        int start = 0;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }

            // Which array does pivot belong to.
            bool pivotArray = existsInFirst(nums, start, nums[mid]);

            // Which array does target belong to.
            bool targetArray = existsInFirst(nums, start, target);

            if (pivotArray ^ targetArray)
            { // If pivot and target both exist in different sorted arrays.
                if (pivotArray)
                {
                    start = mid + 1; // pivot in the first, target in the second.
                }
                else
                {
                    end = mid - 1;
                }
            }
            else
            { // If pivot and target exists in the same array.
                if (nums[mid] > target)
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
        }

        return -1;
    }
};
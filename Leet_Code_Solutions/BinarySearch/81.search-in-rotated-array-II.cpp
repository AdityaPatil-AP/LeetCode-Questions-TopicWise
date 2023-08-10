class Solution
{
public:
    bool isBinarySearchHelpful(vector<int> &nums, int start, int element)
    {
        return nums[start] != element;
    }

    bool existsInFirst(vector<int> &nums, int start, int element)
    {
        return nums[start] <= element;
    }

    bool search(vector<int> &nums, int target)
    {
        // Editorial Approach.
        int n = nums.size();
        if (n == 0)
            return false;
        int end = n - 1;
        int start = 0;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target)
            {
                return true;
            }

            if (!isBinarySearchHelpful(nums, start, nums[mid]))
            {
                start++;
                continue;
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

        return false;

        // // Find the index where the Rotation is performed.
        // int n = nums.size();
        // int rotatedIndex = 0;
        // for(int i = 1;i < n;i++){
        //     if(nums[i]  < nums[i - 1]){
        //         rotatedIndex = i;
        //         break;
        //     }
        // }

        // // Searching using Binary Search for the target in
        // // two Subdivisions, [0, rotatedIndex - 1] and [rotatedIndex, n - 1].

        // bool search1 = isPresent(nums, target, 0, rotatedIndex - 1);
        // bool search2 = isPresent(nums, target, rotatedIndex, n - 1);

        // if(search1 || search2){
        //     return true;
        // }
        // return false;
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
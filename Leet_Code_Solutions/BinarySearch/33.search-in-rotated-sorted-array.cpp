class Solution
{
public:
    bool existsInFirst(vector<int> &nums, int start, int element)
    {
        return nums[start] <= element;
    }

    int binarySearch(vector<int> &nums, int start, int end, int target)
    {
        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target)
                return mid;

            else if (nums[mid] > target)
                end = mid - 1;
            else
                start = mid + 1;
        }

        return -1;
    }

    int search(vector<int> &nums, int target)
    {
        // Approach 2.
        // find the index of the smallest element and divide the search space in 2
        // parts.
        int n = nums.size();
        int left = 0, right = n - 1;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[n - 1])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        int answer = binarySearch(nums, 0, left - 1, target);
        if (answer != -1)
        {
            return answer;
        }

        return binarySearch(nums, left, n - 1, target);

        // // Approach 1.
        // int n = nums.size();
        // int end = n - 1;
        // int start = 0;

        // while(start <= end){
        //     int mid = start + (end - start)/2;

        //     if(nums[mid] == target){
        //         return mid;
        //     }

        //     // Which array does pivot belong to.
        //     bool pivotArray = existsInFirst(nums, start, nums[mid]);

        //     // Which array does target belong to.
        //     bool targetArray = existsInFirst(nums, start, target);

        //     if(pivotArray ^ targetArray){ // If pivot and target both exist in different sorted arrays.
        //         if(pivotArray){
        //             start = mid + 1; // pivot in the first, target in the second.
        //         }
        //         else{
        //             end = mid - 1;
        //         }
        //     }
        //     else{ // If pivot and target exists in the same array.
        //         if(nums[mid] > target){
        //             end = mid - 1;
        //         }
        //         else{
        //             start = mid + 1;
        //         }
        //     }
        // }

        // return -1;
    }
};
class Solution
{
public:
    int searchInsert(vector<int> &arr, int target)
    {
        // int n = arr.size();
        // int low = 0, high = n - 1;
        // while(low <= high){
        //     int mid = low + (high - low)/2;
        //     if(target == arr[mid]){
        //         return mid;
        //     }
        //     else if(target > arr[mid]){
        //         // edge case
        //         if(mid == n - 1)
        //             return n;
        //         if(target < arr[mid + 1]){
        //             return mid + 1;
        //         }
        //         low = mid + 1;
        //     }
        //     else if(target < arr[mid]){
        //         if(mid == 0){
        //             return 0;
        //         }
        //         high = mid - 1;
        //     }
        // }
        // return 0;

        int n = arr.size();
        int l = 0, r = n - 1;
        while (l <= r)
        {
            int mid = (l + (r - l) / 2);
            if (arr[mid] == target)
                return mid;
            else if (arr[mid] < target)
            {
                if (mid == n - 1)
                    return n;
                l = mid + 1;
            }
            else if (target < arr[mid])
            {
                if (mid == 0)
                    return 0;
                if (arr[mid - 1] < target)
                    return mid;
                r = mid - 1;
            }
        }
        return 0;

        // Using lower_bound inbuilt function.
        //         int j = lower_bound(arr.begin(), arr.end(), target) - arr.begin();

        //         return j;
    }
};
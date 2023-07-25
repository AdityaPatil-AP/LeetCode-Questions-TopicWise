class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int n = arr.size();
        int low = 1, high = n - 2;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            // Peak Element is the one which is greater than the previous element as well as
            // succeeding element.
            if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
            {
                return mid;
            }
            // If the current element is greater than the preceding element but less than the succeeding element
            // which means that it is present in the left half to the peak element. So increase the low.
            else if (arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1])
            {
                if (mid == n - 2)
                {
                    return mid;
                }
                low = mid + 1;
            }
            // If the current element is smaller than the preceding element and greater than the succeeding element
            // then it is present in right half to the peak element reference. So decrease the high.
            else if (arr[mid] > arr[mid + 1] && arr[mid] < arr[mid - 1])
            {
                if (mid == 1)
                    return 1;
                high = mid - 1;
            }
        }
        return 0;
    }
};
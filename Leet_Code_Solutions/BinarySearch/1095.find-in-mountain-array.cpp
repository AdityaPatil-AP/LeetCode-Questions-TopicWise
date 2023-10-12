/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution
{
public:
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        // Interactive Problem.
        if (mountainArr.length() < 3)
        {
            return -1;
        }

        // Fetch the kth-index and length of the mountain array.
        int n = mountainArr.length();
        int low = 1, high = n - 1;
        int peak = 0;
        while (low <= high)
        {
            int mid = (low + (high - low) / 2);
            int curr = mountainArr.get(mid);
            int next = mountainArr.get(mid + 1);
            int prev = mountainArr.get(mid - 1);
            if (prev < curr && curr > next)
            {
                peak = mid;
                break;
            }
            else if (prev > curr)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        cout << mountainArr.get(peak) << endl;

        // checking in 1st part.
        low = 0, high = peak;
        while (low <= high)
        {
            int mid = (low + (high - low) / 2);
            int curr = mountainArr.get(mid);
            if (curr == target)
            {
                return mid;
            }
            else if (curr > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        // Check in the second part.
        low = peak, high = n - 1;
        while (low <= high)
        {
            int mid = (low + (high - low) / 2);
            int curr = mountainArr.get(mid);
            if (curr == target)
            {
                return mid;
            }
            else if (curr > target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return -1;
    }
};
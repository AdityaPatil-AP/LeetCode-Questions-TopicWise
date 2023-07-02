class Solution
{
public:
    bool calc(vector<int> &nums, int k, int curr)
    {
        // I have to check whether i can choose k elements if i have curr as maximum.
        for (int i = 0; i < nums.size();)
        {
            if (nums[i] <= curr)
            {
                i += 2;
                k--;
            }
            else
            {
                i++;
            }
            if (k == 0)
                return true;
        }
        return (k == 0);
    }

    int minCapability(vector<int> &nums, int k)
    {
        // I will create two max heaps for alternate positions in the nums array.
        int n = nums.size();

        // Whenever there is a maximum and minimum based problem then we must opt for Binary Search.

        // Here we have to find the minimum capability of all the capabilities. (capability - maximum among all the houses we selected).

        // Our answer can be in the range - ( 1 - 1e9 ).

        int low = 1, high = 1e9;
        int ans = 0;
        while (low <= high)
        {
            int mid = (low) + (high - low) / 2;
            if (calc(nums, k, mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};
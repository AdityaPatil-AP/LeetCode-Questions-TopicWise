class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        // Using Sorting and Maths.
        // Can be done by using Binary Search as well.

        sort(nums.begin(), nums.end());

        int n = nums.size();

        int mid = n / 2;

        int midval = nums[mid];

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += abs(nums[i] - midval);
        }

        return ans;
    }
};
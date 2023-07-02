class Solution
{
public:
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        // So linear search for the divisor will give us time limit exceeded.
        // Therefore we go for Binary Search.
        // Here we see that it is possible to reduce the search space into half after one operation.

        int l = 1, r = *max_element(nums.begin(), nums.end());
        int ans = 1;
        while (l <= r)
        {
            int mid = (l + (r - l) / 2);
            if (isPossible(mid, nums, threshold))
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }

        return ans;
    }

    bool isPossible(int m, vector<int> &nums, int threshold)
    {
        int sum = 0;
        for (auto i : nums)
        {
            sum += ceil((double)i / m);
        }
        return (sum <= threshold);
    }
};
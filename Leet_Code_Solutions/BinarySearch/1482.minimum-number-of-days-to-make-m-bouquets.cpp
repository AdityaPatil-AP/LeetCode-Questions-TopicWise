class Solution
{
public:
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        // Minimum Number of days to make m bouqets.

        // We will check if that after 1st day can we make m bouqets.
        // It will go upto max number in bloomDay.

        // Doing so will give us time limit exceeded in the Linear Search Method.

        // So we will try it by using binary search and reducing the search space.

        int ans = -1;
        int l = 1, r = 1e9;
        while (l <= r)
        {
            int mid = (l + (r - l) / 2);
            if (isPossible(mid, bloomDay, m, k))
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return ans;
    }

    bool isPossible(int mid, vector<int> &bloomDay, int m, int k)
    {
        int count = 0;
        int bouquetsMade = 0;

        for (auto i : bloomDay)
        {
            if (count == k)
            {
                bouquetsMade++;
                count = 0;
            }
            if (i <= mid)
                count++;
            else
                count = 0;
        }
        if (count == k)
            bouquetsMade++;
        return (bouquetsMade >= m);
    }
};
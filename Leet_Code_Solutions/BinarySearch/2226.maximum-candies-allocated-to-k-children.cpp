class Solution
{
public:
    int maximumCandies(vector<int> &candies, long long k)
    {
        // Maximum candies they can get can be between 1 to 1e12.
        // Depending upon the children.

        long long l = 1, r = 1e7;
        long long ans = 0;
        while (l <= r)
        {
            long long mid = (l + (r - l) / 2);
            if (isPossible(mid, candies, k))
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }

        return ans;
    }

    bool isPossible(long long m, vector<int> &candies, long long k)
    {
        long long mCandiesGot = 0;
        for (auto i : candies)
        {
            mCandiesGot += (i / m);
        }

        return (mCandiesGot >= k);
    }
};
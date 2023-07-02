class Solution
{
public:
    long long minimumPerimeter(long long neededApples)
    {
        // Math + binary search.

        long long l = 1, r = 1e6;
        long long ans = 1;
        while (l <= r)
        {
            long long mid = (l + (r - l) / 2);
            if (isPossible(mid, neededApples))
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }

        return ans * 8;
    }
    g

        bool
        isPossible(long long m, long long neededApples)
    {
        long long int curr = (2 * m * (m + 1) * (2 * m + 1));
        return (curr >= neededApples);
    }
};
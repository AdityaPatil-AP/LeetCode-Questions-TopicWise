class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        // Minimum if all piles contain 0 bananas at the start.
        // then our answer can be 0.
        // Maximum value of k can be maximum element in piles.

        // Here we can see that if answer is not possible for some k,
        // then answer is definitely not possible for left half(less than k).

        long long int l = 1, r = 1e9;
        int ans = 0;
        while (l <= r)
        {
            long long int mid = (l + (r - l) / 2);
            if (isPossible(mid, piles, h))
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }

        return ans;
    }

    bool isPossible(long long int m, vector<int> &piles, int h)
    {
        long long currTime = 0;
        for (auto i : piles)
            currTime += ceil(double(i) / m);

        return currTime <= h;
    }
};
class Solution
{
public:
    int minimumAddedCoins(vector<int> &coins, int target)
    {
        sort(coins.begin(), coins.end());

        int addedCoins = 0;
        long maxReachable = 0;

        for (int c : coins)
        {
            while (maxReachable + 1 < c)
            {
                maxReachable += (maxReachable + 1);
                addedCoins++;
            }

            maxReachable += c;

            if (maxReachable >= target)
            {
                return addedCoins;
            }
        }

        while (maxReachable < target)
        {
            maxReachable += (maxReachable + 1);
            addedCoins++;
        }

        return addedCoins;
    }
};
#define ll long long int
class Solution
{
public:
    long long maxPower(vector<int> &stations, int range, int k)
    {
        // now the maximum power can be (10 ^ 5) * (10 ^ 9) = (10 ^ 14).

        // Minimum power can be 0.

        // Now we can check through linear search that whether maximum possible minimum power == 1 is
        // possible for every city or not.

        // But going linearly will give us time limit exceeded.

        // Let's see if we can effeciently solve this problem by reducing the search space.

        // If the maximum possible minimum power as 5 is possible then it is also true minimum power less than
        // 5.

        // Which means we don't need to check in the left half of the search space. So Binary Search can be applied.

        // A power station at ith station is giving power to max(0, i - r) <= i <= min(n - 1, i + r) stations.
        // Let's do this computation through prefix sum as otherwise this process will also give time limit
        // exceeded.
        int n = stations.size();

        vector<long long> powerStations(n, 0);

        for (int i = 0; i < n; i++)
        {
            int start = max(0, i - range);
            int end = min(n - 1, i + range);

            powerStations[start] += stations[i];
            if ((end + 1) < n)
                powerStations[end + 1] += ((-1) * stations[i]);
        }

        // Using the Prefix sum to compute the power of each city.
        for (int i = 1; i < n; i++)
        {
            powerStations[i] += powerStations[i - 1];
        }

        long long l = 0, r = 1e11;
        long long ans = 0;
        while (l <= r)
        {
            long long mid = (l + (r - l) / 2);
            if (isPossible(mid, powerStations, range, k))
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }

        return ans;
    }

    bool isPossible(long long mid, vector<long long> &powerStations, int r, int k)
    {
        int n = powerStations.size();
        vector<long long> extraStations(n, 0);

        for (int i = 0; i < n; i++)
        {
            extraStations[i] += (i > 0) ? extraStations[i - 1] : 0;

            ll currStations = powerStations[i] + extraStations[i];
            if (currStations >= mid)
                continue;

            // If there is sufficient power we have to build some power stations. But where to build it.
            // It would best and greedy to setup them in such a way that current station is at a position (i - r)
            // with respect to the station where it is build so that maximum cities get the power through this station.

            long long diff = (mid - currStations);

            // If sufficient power stations are present then build them otherwise just return false.
            if (k >= diff)
                k -= diff;
            else
                return false;

            extraStations[i] += diff;
            if ((i + (2 * r) + 1) < n)
                extraStations[i + (2 * r) + 1] -= diff;
        }

        return true;
    }
};
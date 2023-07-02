class Solution
{
public:
    long long minimumTime(vector<int> &time, int totalTrips)
    {
        // We can go linearly for each time, and calculate the totals trips using this much amount of time.

        // If the currtrips >= totalTrips, then that is our answer.

        // But this will give us time limit exceeded.

        // So we have to opt for Binary Search.
        sort(time.begin(), time.end());
        long long ans = 1;
        long long start = 1, end = 1e14;
        while (start <= end)
        {
            long long mid = start + (end - start) / 2;
            if (isPossible(mid, time, totalTrips))
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return ans;
    }

    bool isPossible(long long m, vector<int> &time, int totalTrips)
    {
        long long currTrips = 0;
        for (int i = 0; i < time.size(); i++)
        {
            currTrips += (m / (long long)time[i]);
        }

        return (currTrips >= totalTrips);
    }
};
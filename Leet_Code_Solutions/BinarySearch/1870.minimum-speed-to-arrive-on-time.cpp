class Solution
{
public:
    bool calc(int speed, vector<int> &dist, double hour)
    {
        double time = 0;
        int n = dist.size();
        for (int i = 0; i < n - 1; i++)
        {
            time += ceil((double)dist[i] / speed);
        }
        time += (double)dist[n - 1] / speed;
        return (time <= hour);
    }

    int minSpeedOnTime(vector<int> &dist, double hour)
    {
        // This minimum speed can be anything between 0 and 1e7

        int low = 1, high = 1e7;

        if ((double)dist.size() > ceil(hour))
        {
            return -1;
        }
        int ans = -1;
        while (low <= high)
        {
            int mid = (low + (high - low) / 2);
            if (calc(mid, dist, hour))
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
class Solution
{
public:
    int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks)
    {
        int n = capacity.size();
        int count = 0;
        int rem = additionalRocks;
        vector<int> required(n, 0);
        for (int i = 0; i < n; i++)
        {
            required[i] = capacity[i] - rocks[i];
        }
        // Greedy - Sorting.
        sort(required.begin(), required.end());
        for (int i = 0; i < n; i++)
        {
            if (required[i] <= additionalRocks)
            {
                additionalRocks -= required[i];
                count++;
            }
            else
                break;
        }
        return count;
    }
};
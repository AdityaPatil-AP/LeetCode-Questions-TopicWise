class Solution
{
public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold)
    {
        // Classic Sliding window problem.

        // If window Problem -> 1) sliding window implemenation is hard.

        // Try 2) Prefix Sum and Hash Table(map) approach.
        int i = 0, j = 0;
        int ans = 0;
        int sum = 0;

        while (j < arr.size())
        {
            sum += arr[j];

            if ((j - i + 1) < k)
            {
                j++;
                continue;
            }
            else
            {
                double average = (double)sum / k;

                if (average >= threshold)
                    ans++;

                sum -= arr[i];
                i++;
            }
            j++;
        }

        return ans;
    }
};
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();

        vector<int> allocation(n, 1);

        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                allocation[i] = 1 + allocation[i - 1];
            }
        }

        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                allocation[i] = max(allocation[i], 1 + allocation[i + 1]);
            }
        }

        int sum = accumulate(allocation.begin(), allocation.end(), 0);

        return sum;
    }
};
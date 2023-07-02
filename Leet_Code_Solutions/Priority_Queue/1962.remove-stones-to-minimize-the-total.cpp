class Solution
{
public:
    int minStoneSum(vector<int> &piles, int k)
    {
        int total = 0;
        priority_queue<int> pq;
        int n = piles.size();
        for (int i = 0; i < n; i++)
        {
            pq.push(piles[i]);
            total += piles[i];
        }
        while (k--)
        {
            total -= pq.top() / 2;
            int m = pq.top() - pq.top() / 2;
            pq.pop();
            pq.push(m);
        }
        return total;
    }
};
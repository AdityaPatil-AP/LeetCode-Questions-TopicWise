class Solution
{
public:
    int minOperations(int n)
    {
        int ans = 0;
        int j = 1;
        for (int j = 1, i = 0; i < n / 2; j += 2, i++)
        {
            ans += (n - j);
        }
        return ans;
    }
};
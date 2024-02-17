class Solution
{
public:
    int maxSelectedElements(vector<int> &num)
    {

        unordered_map<int, int> dp;

        sort(num.begin(), num.end());

        int res = 0;

        for (int &a : num)
        {
            res = max(res, dp[a + 1] = 1 + dp[a]);
            res = max(res, dp[a] = dp[a - 1] + 1);
        }

        return res;
    }
};
class Solution
{
public:
    int maxScore(string s)
    {
        int ans = 0;

        int n = s.size();

        for (int i = 0; i < n - 1; i++)
        {
            int curr = 0;

            for (int j = 0; j <= i; j++)
            {
                if (s[j] == '0')
                    curr++;
            }

            for (int j = i + 1; j < n; j++)
            {
                if (s[j] == '1')
                    curr++;
            }

            ans = max(ans, curr);
        }

        return ans;
    }
};

class Solution
{
public:
    int maxScore(string s)
    {
        int ans = 0;

        int n = s.size();

        vector<int> suffixSum(n, 0);
        suffixSum[n - 1] = s[n - 1] - '0';
        for (int i = n - 2; i >= 0; i--)
        {
            suffixSum[i] = suffixSum[i + 1] + (s[i] - '0');
        }

        int zeroCount = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == '0')
                zeroCount++;
            int curr = zeroCount + suffixSum[i + 1];
            ans = max(ans, curr);
        }

        return ans;
    }
};
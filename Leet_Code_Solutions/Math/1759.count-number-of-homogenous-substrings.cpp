class Solution
{
public:
    int countHomogenous(string s)
    {
        int ans = 0;
        int mod = 1e9 + 7;

        int count = 0;
        int n = s.size();
        char prev = s[0];
        for (int i = 0; i < n; i++)
        {
            if (s[i] == prev)
                count++;
            else
                count = 1;

            ans = (ans + count) % mod;
            prev = s[i];
        }

        return ans;
    }
};
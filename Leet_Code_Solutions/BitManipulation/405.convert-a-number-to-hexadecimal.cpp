class Solution
{
public:
    string toHex(int n)
    {
        if (n == 0)
            return "0";
        string ans = "";
        for (int i = 0; i < 32; i += 4)
        {
            int sum = 1 * ((n >> i) & 1) + 2 * ((n >> (i + 1)) & 1) + 4 * ((n >> (i + 2)) & 1) + 8 * ((n >> (i + 3)) & 1);

            if (sum <= 9)
            {
                ans += to_string(sum);
            }
            else
            {
                ans += ('a' + (sum - 10));
            }
        }

        reverse(ans.begin(), ans.end());
        int i = 0;
        while (ans[i] == '0')
        {
            i++;
        }

        ans.erase(0, i);

        return ans;
    }
};
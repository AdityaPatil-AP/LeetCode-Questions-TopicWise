class Solution
{
public:
    int minFlips(int a, int b, int c)
    {
        int ans = 0;
        for (int i = 0; i < 30; i++)
        {
            int bit_a = (a >> i) & 1;
            int bit_b = (b >> i) & 1;

            int bit_c = (c >> i) & 1;

            if ((bit_a + bit_b) == 0)
            {
                if (bit_c == 1)
                {
                    ans += 1;
                }
            }
            else if (bit_a + bit_b == 1)
            {
                if (bit_c == 0)
                {
                    ans += 1;
                }
            }
            else
            {
                if (bit_c == 0)
                {
                    ans += 2;
                }
            }
        }

        return ans;
    }
};
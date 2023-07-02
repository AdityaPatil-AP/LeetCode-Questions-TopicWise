class Solution
{
public:
    int reverse(int x)
    {
        // can be done using long.
        // but the question demands to find the reverse of a number by using a 32-bit integer only.
        // Using mod and upper limits.
        int ans = 0;
        while (x != 0)
        {
            int rem = x % 10;
            x = x / 10;
            if ((ans > INT_MAX / 10) || (ans == INT_MAX / 10 && rem > 7))
            {
                return 0;
            }
            if ((ans < INT_MIN / 10) || (ans == INT_MIN / 10 && rem < -8))
            {
                return 0;
            }
            ans = (ans * 10) + rem;
        }
        return ans;
    }
};

// 2,147,483,647
// -2,147, 483,648.

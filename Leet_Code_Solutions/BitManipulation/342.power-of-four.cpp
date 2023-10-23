class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        // Is power of four.
        // Bit Manipulation.
        if (n <= 0)
            return false;

        int setBitCountEven = 0, setBitCountOdd = 0;
        for (int i = 0; i < 32; i += 2)
        {
            if (((n >> i) & 1) == 1)
            {
                setBitCountEven++;
            }
            if (((n >> (i + 1)) & 1) == 1)
            {
                setBitCountOdd++;
            }
        }

        return (setBitCountEven == 1 && setBitCountOdd == 0);
    }
};
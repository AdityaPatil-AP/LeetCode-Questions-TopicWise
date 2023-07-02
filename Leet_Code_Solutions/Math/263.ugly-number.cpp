class Solution
{
public:
    bool isUgly(int n)
    {
        // A negative integer can never be ugly therefore if we encounter them just return false.
        if (n <= 0)
            return false;
        while (n % 2 == 0 || n % 3 == 0 || n % 5 == 0)
        {
            if (n % 2 == 0)
                n /= 2;
            if (n % 3 == 0)
                n /= 3;
            if (n % 5 == 0)
                n /= 5;
        }

        if (n == 1)
            return true;
        return false;
    }
};
class Solution
{
public:
    int kthGrammar(int n, int k)
    {
        if (n == 1)
            return 0;
        if (n == 2 && k == 1)
            return 0;
        if (n == 2 && k == 2)
            return 1;

        int prev = kthGrammar(n - 1, (k + 1) / 2);

        if (prev == 0 && k % 2 == 1)
            return 0;
        else if (prev == 0 && k % 2 == 0)
            return 1;
        else if (prev == 1 && k % 2 == 1)
            return 1;
        return 0;
    }
};
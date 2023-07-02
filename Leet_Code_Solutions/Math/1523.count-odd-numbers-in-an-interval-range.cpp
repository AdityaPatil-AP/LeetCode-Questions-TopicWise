class Solution
{
public:
    int countOdds(int l, int h)
    {
        if (l % 2 == 0)
            l++;
        if (h % 2 == 0)
            h--;
        return 1 + (h - l) / 2;
    }
};
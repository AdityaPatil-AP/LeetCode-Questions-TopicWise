class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        char result = 0;
        for (char c : s + t)
        {
            result ^= c;
        }
        return result;
    }
};
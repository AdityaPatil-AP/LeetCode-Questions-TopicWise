class Solution
{
public:
    void reverse(string &s, int start, int end)
    {
        while (start < end)
        {
            swap(s[start], s[end]);
            start++, end--;
        }
    }

    string reverseWords(string s)
    {
        int k = 0, i = 0;
        for (i = 0, k = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                // reverse(s.begin() + k, s.begin() + i);
                reverse(s, k, i - 1);
                k = i + 1;
            }
        }
        if (k < i)
        {
            reverse(s, k, i - 1);
        }
        return s;
    }
};

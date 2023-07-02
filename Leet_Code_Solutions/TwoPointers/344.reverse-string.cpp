class Solution
{
public:
    void helper(vector<char> &s, int index, int size)
    {
        if (index > (size - 1) / 2)
        {
            return;
        }
        swap(s[index], s[size - index - 1]);
        helper(s, index + 1, size);
    }

    void reverseString(vector<char> &s)
    {
        // int size = s.size();
        // helper(s, 0, size);

        // Can be easily implemented Using Two Pointer Approach.
        int start = 0, end = s.size() - 1;
        while (start < end)
        {
            swap(s[start], s[end]);
            start++, end--;
        }
    }
};
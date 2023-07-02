class Solution
{
public:
    string reverseWords(string s)
    {
        string res;
        int i = 0, n = s.size();
        while (i < n)
        {
            // skipping spaces in between.
            while (i < n && s[i] == ' ')
            {
                i++;
            }

            if (i >= n)
                break;

            int j = i;
            // finding the word and breaking when we encounter a space.
            while (j < n && s[j] != ' ')
            {
                j++;
            }

            string sub = s.substr(i, j - i);

            if (res.size() == 0)
                res = sub;
            else
                res = sub + " " + res;

            i = j + 1;
        }

        return res;
    }
};
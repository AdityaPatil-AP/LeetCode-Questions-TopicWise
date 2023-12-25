class Solution
{
public:
    int minOperations(string s)
    {
        int start0 = 0;
        int start1 = 0;

        int n = s.size();
        for (int i = 0; i < s.size(); i += 2)
        {
            if (s[i] == '0')
                start1++;
            if (s[i] == '1')
                start0++;

            if (i + 1 < n && s[i + 1] == '0')
                start0++;
            if (i + 1 < n && s[i + 1] == '1')
                start1++;
        }

        return min(start0, start1);
    }
};
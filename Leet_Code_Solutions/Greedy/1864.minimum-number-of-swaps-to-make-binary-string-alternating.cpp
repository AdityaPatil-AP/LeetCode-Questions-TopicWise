class Solution
{
public:
    int minSwaps(string s)
    {
        // Either 0's on odd positions. or 2nd option 0's on even positions.

        unordered_map<string, int> mp;
        int count0 = count(s.begin(), s.end(), '0');
        int count1 = count(s.begin(), s.end(), '1');

        if (abs(count0 - count1) > 1)
        {
            return -1;
        }

        int ans = s.size() / 2;
        if (count0 > count1)
        {
            ans = minFind(s, '0', '1');
        }
        else if (count1 > count0)
        {
            ans = minFind(s, '1', '0');
        }
        else
        {
            ans = minFind(s, '1', '0');
            ans = min(ans, minFind(s, '0', '1'));
        }

        return ans;
    }

    int minFind(string &s, char a, char b)
    {
        int wrongPos = 0;

        for (int i = 0; i < s.size(); i += 2)
        {
            if (s[i] != a)
                wrongPos++;
        }

        return wrongPos;
    }
};
class Solution
{
public:
    map<char, int> mp;
    void init()
    {
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
    }
    int romanToInt(string s)
    {
        init();
        int ans = 0;
        for (int i = 0; i < s.size();)
        {
            if ((i + 1) < s.size() && mp[s[i]] < mp[s[i + 1]])
            {
                ans += (mp[s[i + 1]] - mp[s[i]]);
                i += 2;
            }
            else
            {
                ans += mp[s[i]];
                i++;
            }
        }
        return ans;
    }
};
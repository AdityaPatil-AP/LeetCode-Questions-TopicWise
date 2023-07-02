#define ll long long int

class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        unordered_map<string, ll> mp;
        ll n = words.size();
        for (int i = 0; i < n; i++)
        {
            mp[words[i]]++;
        }
        bool sameLetterStringFound = false;
        ll ans = 0;
        for (auto it : mp)
        {
            string m = it.first;
            reverse(m.begin(), m.end());
            if (mp.find(m) != mp.end())
            {
                if (m[0] == m[1])
                {
                    ans += ((mp[it.first]) / 2) * 2;
                    if (mp[it.first] % 2 == 1)
                        sameLetterStringFound = true;
                }
                else
                {
                    ans += (min(mp[it.first], mp[m]) * 2);
                    mp.erase(m);
                }
            }
        }
        if (sameLetterStringFound)
            ans += 1;
        return (ans * 2);
    }
};
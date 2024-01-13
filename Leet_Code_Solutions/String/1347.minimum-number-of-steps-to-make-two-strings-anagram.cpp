class Solution
{
public:
    int minSteps(string s, string t)
    {
        int common = 0;

        int n = s.size();

        unordered_map<char, int> mp1, mp2;

        for (auto it : s)
            mp1[it]++;
        for (auto it : t)
            mp2[it]++;

        for (char c = 'a'; c <= 'z'; c++)
        {
            common += min(mp1[c], mp2[c]);
        }

        return (n - common);
    }
};
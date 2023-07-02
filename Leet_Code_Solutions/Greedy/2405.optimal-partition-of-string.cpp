// Optimal Solution.

class Solution
{
public:
    int partitionString(string s)
    {
        vector<int> mp(26, -1);
        int cnt = 1;
        int substringStart = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (mp[s[i] - 'a'] < substringStart)
            {
                mp[s[i] - 'a'] = i;
            }
            else
            {
                cnt++;
                substringStart = i;
                mp[s[i] - 'a'] = i;
            }
        }

        return cnt;
    }
};

class Solution
{
public:
    int partitionString(string s)
    {
        set<char> st;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (st.find(s[i]) == st.end() || st.size() == 0)
            {
                st.insert(s[i]);
            }
            else
            {
                cnt++;
                st.erase(st.begin(), st.end());
                i--;
            }
        }
        if (st.size() != 0)
        {
            cnt++;
        }
        return cnt;
    }
};

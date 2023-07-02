class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < s1.size(); i++)
        {
            mp[s1[i]]++;
        }

        int window = s1.size();

        int j = 0;
        int i = 0;
        unordered_map<int, int> mp1;
        while (j < s2.size())
        {
            mp1[s2[j]]++;
            if ((j - i + 1) < window)
            {
                j++;
                continue;
            }
            if ((j - i + 1) == window)
            {
                bool ans = true;
                for (auto it : mp1)
                {
                    if (mp1[it.first] == mp[it.first])
                    {
                        continue;
                    }
                    else
                    {
                        ans = false;
                        break;
                    }
                }

                if (ans)
                    return true;
                else
                {
                    mp1[s2[i]]--;
                    i++;
                }
            }
            j++;
        }

        return false;
    }
};

class Solution
{
public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        map<char, int> mp;
        for (int i = 0; i < 26; i++)
        {
            mp[order[i]] =  i;
        }

        bool ans = true;
        for (int i = 0; i < words.size() - 1; i++)
        {
            int n = words[i].size();
            int m = words[i + 1].size();
            if (n > m && (words[i].substr(0, m) == words[i + 1]))
            {
                ans = false;
                break;
            }
            for (int j = 0; j < min(n, m); j++)
            {
                if (mp[words[i][j]] < mp[words[i + 1][j]])
                {
                    break;
                }
                else if (mp[words[i][j]] == mp[words[i + 1][j]])
                {
                    continue;
                }
                else
                {
                    ans = false;
                    break;
                }
            }
            if (!ans)
                break;
        }

        return ans;
    }
};
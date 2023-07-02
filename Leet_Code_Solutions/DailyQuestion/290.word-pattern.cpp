class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        map<char, string> mp;

        vector<string> collect;
        stringstream ss(s);
        string word = "";
        while (ss >> word)
        { // use it when we are taking the input.
            collect.push_back(word);
        }
        if (pattern.size() != collect.size())
            return false;
        set<string> st;
        for (int i = 0; i < pattern.size(); i++)
        {
            if (mp[pattern[i]] == "")
            {
                if (st.find(collect[i]) != st.end())
                {
                    return false;
                }
                mp[pattern[i]] = collect[i];
                st.insert(collect[i]);
            }
            else if (mp[pattern[i]] != collect[i])
            {
                return false;
            }
        }
        return true;
    }
};
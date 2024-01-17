class Solution
{
public:
    bool closeStrings(std::string word1, std::string word2)
    {
        if (word1.size() != word2.size())
        {
            return false;
        }

        map<char, int> mp1, mp2;

        for (auto it : word1)
            mp1[it]++;
        for (auto it : word2)
            mp2[it]++;

        vector<int> freq1;
        vector<int> freq2;
        for (auto it : mp1)
            freq1.push_back(it.second);
        for (auto it : mp2)
        {
            if (mp1.find(it.first) == mp1.end())
            {
                return false;
            }
            freq2.push_back(it.second);
        }

        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        // This check also ensures that there are same number of unique characters.
        return (freq1 == freq2);
    }
};
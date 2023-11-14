class Solution
{
public:
    bool isVowel(char curr)
    {
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        for (int i = 0; i < vowels.size(); i++)
        {
            if (vowels[i] == curr)
                return true;
        }

        return false;
    }

    string sortVowels(string s)
    {
        string temp;
        int n = s.size();

        for (auto curr : s)
        {
            if (isVowel(curr))
                temp.push_back(curr);
        }

        sort(temp.begin(), temp.end());

        string ans;

        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (isVowel(s[i]))
            {
                ans += temp[j++];
            }
            else
            {
                ans += s[i];
            }
        }

        return ans;
    }
};

class Solution
{
public:
    bool halvesAreAlike(std::string s)
    {
        int n = s.size();
        unordered_set<char> st({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});

        int count1 = 0;
        int count2 = 0;
        for (int i = 0; i < n / 2; i++)
        {
            if (st.find(s[i]) != st.end())
                count1++;
            if (st.find(s[n / 2 + i]) != st.end())
                count2++;
        }

        return (count1 == count2);
    }
};

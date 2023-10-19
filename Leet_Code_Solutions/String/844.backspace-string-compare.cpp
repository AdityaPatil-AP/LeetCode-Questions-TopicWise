class Solution
{
public:
    string finder(string s)
    {
        string newcurr = "";
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (!st.empty() && s[i] == '#')
            {
                st.pop();
            }
            else if (s[i] != '#')
            {
                st.push(s[i]);
            }
        }

        while (!st.empty())
        {
            newcurr.push_back(st.top());
            st.pop();
        }

        reverse(newcurr.begin(), newcurr.end());
        return newcurr;
    }

    bool backspaceCompare(string s, string t)
    {
        string curr1 = finder(s);
        string curr2 = finder(t);

        return (curr1 == curr2);
    }
};
class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        // We have to store the last index in order to keep the check,
        // that if we remove them here, do we have any occurence of this character
        // after this index.
        // Storing last index of occuring character.
        vector<int> li(26, -1);

        // Keeping a bool array to indicated whether the current character is already
        // present in our answer stack.

        vector<int> vis(26, 0);

        for (int i = 0; i < s.size(); i++)
        {
            li[s[i] - 'a'] = i;
        }

        stack<char> st;

        for (int i = 0; i < s.size(); i++)
        {
            int curr = s[i] - 'a';

            if (vis[curr])
                continue;

            while (st.size() > 0 && s[i] < st.top() && i < li[st.top() - 'a'])
            {
                vis[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(s[i]);
            vis[curr] = true;
        }

        string ans = "";
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
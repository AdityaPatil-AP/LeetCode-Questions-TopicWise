class Solution
{
public:
    string smallestSubsequence(string s)
    {
        // Subsequence dekh ke don't always think of DP, get a clear idea.
        // There can be multiple paths, think of the brute force one.

        // Think Generically if this solution applies to all the possibe formations of strings.

        // to store the last indexes of all characters.
        vector<int> li(26, -1);

        // We need a data structure where we can access the least recently encountered character fastly, go for stack.
        stack<char> st;

        // Before moving ahead, we need to find the last occurences of every character.
        for (int i = 0; i < s.size(); i++)
        {
            li[s[i] - 'a'] = i;
        }

        // We need a boolean array for the keeping the check that the current character is already in the array or not.
        vector<bool> vis(26, false);

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
            ans.push_back(st.top());
            st.pop();
        }

        reverse(begin(ans), end(ans));

        return ans;
    }
};
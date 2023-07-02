class Solution
{
public:
    bool checkPalindrome(string &s, int start, int end)
    {
        int i = start, j = end;
        while (i < j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
            i++, j--;
        }
        return true;
    }

    int solve(string &s, int start, int k, vector<int> &dp)
    {

        if (start >= s.size())
        {
            return 0;
        }
        if (dp[start] != -1)
        {
            return dp[start];
        }
        int ans = 0;
        for (int i = start + k - 1; i < s.size(); i++)
        {
            if (checkPalindrome(s, start, i))
            {
                ans = max(ans, 1 + solve(s, i + 1, k, dp));
            }
        }
        ans = max(ans, solve(s, start + 1, k, dp));
        return dp[start] = ans;
    }

    int maxPalindromes(string s, int k)
    {

        // Using Recursion.
        set<int> st;
        for (int i = 0; i < s.size(); i++)
        {
            st.insert(s[i]);
        }
        if (st.size() == 1)
        {
            return s.size() / k;
        }
        vector<int> dp(2500, -1);
        return solve(s, 0, k, dp);
    }
};
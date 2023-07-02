class Solution
{
public:
    string removeStars(string s)
    {
        int cnt = 0; // number of stars passed from the right.
        int n = s.size();
        string ans = "";
        int i = n - 1;

        while (i >= 0)
        {
            while (i >= 0 && s[i] == '*')
            {
                cnt++;
                i--;
            }
            while (cnt > 0 && s[i] != '*')
            {
                cnt--;
                i--;
            }
            while (i >= 0 && s[i] != '*')
            {
                ans.push_back(s[i]);
                i--;
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
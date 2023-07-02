class Solution
{
public:
    void dfs(int currpos, string str, string &digits, unordered_map<int, string> &mp, vector<string> &ans)
    {
        if (currpos == digits.size())
            ans.push_back(str);
        else
        {
            string word = mp[digits[currpos] - '0'];
            for (int i = 0; i < word.size(); i++)
                dfs(currpos + 1, str + word[i], digits, mp, ans);
        }
    }

    vector<string> letterCombinations(string digits)
    {
        unordered_map<int, string> mp = {{2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};
        vector<string> ans;
        if (!digits.size())
            return ans;
        dfs(0, "", digits, mp, ans);
        return ans;
    }
};
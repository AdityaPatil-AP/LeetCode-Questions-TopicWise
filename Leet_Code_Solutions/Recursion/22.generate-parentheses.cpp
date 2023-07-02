class Solution
{
public:
    //     vector<string> generateParenthesis(int n) {
    //         // Using brute force approach and generating all type of strings that can be formed by n pairs of parentheses.
    //         vector<string> ans;
    //         solve("", 2 * n, ans);
    //         return ans;
    //     }

    //     void solve(string str, int N, vector<string> &ans){
    //         if(size(str) == N){
    //             if(valid(str)) ans.push_back(str);
    //             return;
    //         }
    //         solve(str + '(', N, ans);
    //         solve(str + ')', N, ans);
    //     }

    //     bool valid(string str){
    //         // stack<char> st;
    //         // for(auto m : str){
    //         //     if(m == '(') st.push(m);
    //         //     else{
    //         //         if(!st.empty() && st.top() == '(') st.pop();
    //         //         else return false;
    //         //     }
    //         // }
    //         // if(st.empty()) return true;
    //         // else return false;
    //         int diff = 0;
    //         for(auto &ch : str){
    //             diff += (ch == '(') ? 1 : -1;
    //             if(diff < 0) return false;
    //         }
    //         return !diff;
    //     }

    // BackTracking.
    vector<string> generateParenthesis(int n)
    {
        // vector<string> ans;
        // solve(0, 0, n, "", ans);
        // return ans;

        vector<string> ans;
        solve(n, n, "", 2 * n, ans);
        return ans;
    }
    void solve(int open, int close, string str, int size, vector<string> &ans)
    {
        // if(size(s) == 2*n) ans.push_back(move(s));  // use move to directly push the constructed string into vector instead of creating a copy
        // if(start < n) solve(start + 1, close, n, s + '(', ans);
        // if(close < start) solve(start, close + 1, n, s + ')', ans);

        if (str.size() == size)
        {
            ans.push_back(str);
            return;
        }
        if (open > 0)
            solve(open - 1, close, str + '(', size, ans);
        if (close > open)
            solve(open, close - 1, str + ')', size, ans);
    }
};
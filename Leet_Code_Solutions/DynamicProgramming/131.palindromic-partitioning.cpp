class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        helper(0, path, ans, s);
        return ans;
    }
    
    void helper(int index, vector<string> &path, vector<vector<string>> &ans, string &s){
        if(index == s.size()){
            ans.push_back(path);
            return;
        }
        for(int i = index;i < s.size();i++){
            if(isPalindrome(index, i, s)){
                path.push_back(s.substr(index, i - index + 1));
                helper(i + 1, path, ans, s);
                path.pop_back();
            }
        }
    }
    
    bool isPalindrome(int start, int end, string &s){
        while(start <= end){
            if(s[start++] != s[end--]){
                return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    bool isValid(string s) {
        stack<char> s1;
        for(int i = 0;i < s.size();i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                s1.push(s[i]);
            }
            else if(s[i] == '}') if(!s1.empty() && s1.top() == '{') {s1.pop();continue;} else return false;
            else if(s[i] == ')') if(!s1.empty() && s1.top() == '(') {s1.pop();continue;} else return false;
            else if(s[i] == ']') if(!s1.empty() && s1.top() == '[') {s1.pop();continue;} else return false;
        }
        if(s1.empty()){
            return true;
        }
        else return false;
    }
};
class Solution {
public:
    int calculate(string s) {
        // Using Stack.
        stack<pair<int, int>> st; // {prev_result_value, sign before the bracked};
        long long int res = 0;
        int sign = 1;
        for(int i = 0;i < s.size();i++){
            char c = s[i];
            if(isdigit(c)){
                int temp = 0;
                while(i < s.size() && isdigit(s[i])){
                    temp = (temp * 10) + (s[i] - '0');
                    i++;
                }
                i--;
                res += (temp * sign);
            }
            else if(s[i] == '('){
                st.push({res, sign});
                res = 0;
                sign = 1;
            }
            else if(s[i] == ')'){
                res = (st.top().first + (st.top().second * res));
                st.pop();
            }
            else if(s[i] == '-'){
                sign = -1;
            }
            else if(s[i] == '+') sign = 1;
        }
        return res;
    }
};
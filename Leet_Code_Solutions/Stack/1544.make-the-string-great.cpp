class Solution
{
public:
    string makeGood(string s)
    {
        // Using stack
        // stack<char> st;
        // for(int i = 0;i < s.size();i++){
        //     if(st.empty()){
        //         st.push(s[i]);
        //     }
        //     else{
        //         char m = st.top();
        //         if(m == (32 + s[i]) || (32 + m) == s[i]){
        //             st.pop();
        //         }
        //         else{
        //             st.push(s[i]);
        //         }
        //     }
        // }
        // string ans = "";
        // while(!st.empty()){
        //     ans += st.top();
        //     st.pop();
        // }
        // reverse(ans.begin(), ans.end());
        // return ans;

        // Iterative
        // if s has less than 2 characters, we just return itself.
        //         while (s.size() > 1) {
        //             // 'find' records if we find any pair to remove.
        //             bool find = false;

        //             // Check every two adjacent characters, currChar and nextChar.
        //             for (int i = 0; i < s.size() - 1; ++i) {
        //                 char currChar = s[i], nextChar = s[i + 1];

        //                 // If they make a pair, remove them from 's' and let 'find = true'.
        //                 if (abs(currChar - nextChar) == 32) {
        //                     s = s.substr(0, i) + s.substr(i + 2);
        //                     find = true;
        //                     break;
        //                 }
        //             }

        //             // If we cannot find any pair to remove, break the loop.
        //             if (!find)
        //                 break;
        //         }
        //         return s;

        //         while(s.size() > 1){
        //             bool find = false;

        //             for(int i = 0;i < s.size() - 1;i++){
        //                 if(abs(s[i] - s[i + 1]) == 32){
        //                     s = s.substr(0, i) + s.substr(i + 2);
        //                     find = true;
        //                     break;
        //                 }
        //             }
        //             if(!find){
        //                 break;
        //             }
        //         }
        //         return s;

        // Using Recursion.
        if (s.empty())
            return s;

        for (int i = 0; i < s.size() - 1; i++)
        {
            if (abs(s[i] - s[i + 1]) == 32)
            {
                return makeGood(s.substr(0, i) + s.substr(i + 2));
            }
        }
        return s;
    }
};
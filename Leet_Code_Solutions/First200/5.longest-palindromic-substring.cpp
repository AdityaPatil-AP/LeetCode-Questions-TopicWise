class Solution
{
public:
    // for Brute Force.
    bool checkPalindrome(string &s, int i, int j)
    {
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

    bool checkPalindrome(string &s, int start, int end, vector<vector<int>> &dp, vector<int> &answer)
    {
        if (dp[start][end] != -1)
        {
            return dp[start][end];
        }

        // If my substring is empty or having just one character, then it is a palindrome.
        if (start >= end)
        {
            return dp[start][end] = true;
        }

        // Possibilities...
        bool found = false;
        if (s[start] == s[end])
        {
            found = checkPalindrome(s, start + 1, end - 1, dp, answer);
        }

        // other Possibilities.
        checkPalindrome(s, start + 1, end, dp, answer);
        checkPalindrome(s, start, end - 1, dp, answer);

        if (found == true && (end - start + 1) > answer[2])
        {
            answer[0] = start;
            answer[1] = end;
            answer[2] = (end - start + 1);
        }
        // Memoisations
        dp[start][end] = found;
        return found;
    }

    string longestPalindrome(string s)
    {
        // Brute Force - Create all substrings and sieve out all the palindromic substrings from it.
        // From those palindromic substrings, find the one with the maximum length and return it.

        // string res = "";
        // int n = s.size();
        // for(int i = 0;i < n;i++){
        //     for(int j = i;j < n;j++){
        //         if(j - i + 1 > res.size()){
        //             if(checkPalindrome(s, i, j)){
        //                 res = s.substr(i, j - i + 1);
        //             }
        //         }
        //     }
        // }

        // return res;

        // Using Computation and already storing for a given starting and ending point, whether it is a palindrome or not
        // Thus reducing the palindrome checks in first case from O(n) to O(1).
        // Top Down Approach.
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<int> ans = {0, 0, 1};
        checkPalindrome(s, 0, s.size() - 1, dp, ans);

        return s.substr(ans[0], ans[2]);
    }
};
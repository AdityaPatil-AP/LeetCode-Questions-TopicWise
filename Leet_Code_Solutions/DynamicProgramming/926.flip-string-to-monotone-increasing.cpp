class Solution
{
public:
    int minFlipsMonoIncr(string s)
    {
        // Using Dynamic Windows.
        //         The Resulting string can be considered as  2 consecutive non - overlapping substrings, the
        //         prefix only contains '0' and the suffix only contains '1'.Initially left window is empty, and right window
        //         contains the whole string. Now we increase the size of the left window by 1 therefore decreasing the size of
        //         right window by 1.

        //         We want to change all the characters in the left window to 0 and all the characters in the right window to 1.

        //         left1 - tells the number of ones in left window.
        //         right0 - tells the number of zeoes in right window.

        //         totalFlips - left1 + right0.
        //         Now if we have a string say 00000, which contains all zeroes, if they all are in the right window, we will
        //         have to flip every '0'. But as we iterate through we see that ans is minimising, therefore we have to choose the
        //         minimum values of (left1 + right0) indicating minimum number of flips.

        //         Now at the start all the characters are in the right window.
        //         So the number of flips will be equal to the number of zeroes in the whole array.
        //         int ans = 0;
        //         int m = 0; // Number of flips to be made for the current windows.
        //         for(char c : s){
        //             if(c == '0'){
        //                 m++;
        //             }
        //         }

        //         // Now increase left window size by 1 and decrease the right window size by 1.
        //         ans = m;
        //         for(char c : s){
        //             if(c == '0'){
        //                 ans = min(ans, --m);
        //             }
        //             else{
        //                 ++m;
        //             }
        //         }

        //         return ans;

        // Using dynamic Programming.
        // Finally in Monotonuously Increasing string will have all zeroes at the start followed by all the ones.
        // Now if the string is monotone increasing then all it's prefixes are also monotone increasing. To make the
        // prefix of length i monotone increasing, we can make the prefix of length (i - 1) monotone increasing and
        // consider that whether we can flip the last character or not. This implies the optimisation of the subproblems.
        // which is a characterstic of Dynamic Programming.

        // Let dp[i] - denotes the number of flips to make the prefix of length of i monotone increasing.

        // dp[0] = 0, because an empty string is always monotone increasing.

        // dp[i] = dp[i - 1], if s[i - 1] == '1', because we are appending '1' to the end of a monotone increasing string,
        // and it's still monotone increasing.

        // dp[i] = min(num, dp[i - 1] + 1); if s[i] == '0'
        // 1st case, we don't flip then we have to flip all the ones before it.
        // 2nd case, if we flip then we consider the above case with one more flip.

        // Final answer will be at dp[s.length()];

        int ans = 0, num = 0; // num indicates the number of 1's encountered till now.
        vector<int> dp(s.length() + 1, 0);
        for (int i = 1; i <= s.length(); i++)
        {
            if (s[i - 1] == '0')
            {
                dp[i] = min(1 + dp[i - 1], num);
            }
            else
            {
                dp[i] = dp[i - 1];
                num++;
            }
        }

        return dp[s.length()];
    }
};
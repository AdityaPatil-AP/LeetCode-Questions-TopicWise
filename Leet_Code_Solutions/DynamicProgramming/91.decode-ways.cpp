class Solution
{
public:
    vector<int> dp;
    int numDecodings(string s)
    {
        int n = s.size();
        dp = vector<int>(n, -1);

        return solve(0, s);

        // // dp[i] -> Number of ways to decode the string from ith position till end.
        // int n = s.size();
        // vector<int> dp(n + 1, 0);

        // // One way to decode an empty string.
        // dp[n] = 1;

        // for(int i = n - 1;i >= 0;i--){
        //     if(s[i] == '0'){
        //         continue;
        //     }
        //     string s1 = s.substr(i, 1);

        //     dp[i] += dp[i + 1];
        //     if(i + 1 < n){
        //         string s2 = s.substr(i, 2);
        //         if(stoi(s2) <= 26)
        //             dp[i] += dp[i + 2];
        //     }
        // }

        // return dp[0];
    }

    int solve(int i, string &s)
    {
        int n = s.size();
        if (i == n)
            return 1;

        if (s[i] == '0')
            return 0;

        // Precomputed answer.
        if (dp[i] != -1)
            return dp[i];

        // Take one character.
        int ans = solve(i + 1, s);

        // Take two characters.
        if (i + 1 < n && stoi(s.substr(i, 2)) <= 26)
        {
            ans += solve(i + 2, s);
        }

        return dp[i] = ans;
    }
};
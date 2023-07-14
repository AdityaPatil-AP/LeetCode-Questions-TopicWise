class Solution
{
public:
    int longestSubsequence(vector<int> &arr, int difference)
    {
        // dp[i] -> longest arithmetic subsequence with difference d till
        // index i.

        unordered_map<int, int> mp; // Will store the maximum length of Longest Arithmetic
        // Subsequence corresponding to a given number for the difference d.
        // Here we are using Hashmap dp.
        int n = arr.size();
        int ans = 1;

        for (int i = 0; i < n; i++)
        {
            int before_a = mp.count(arr[i] - difference) ? mp[arr[i] - difference] : 0;
            mp[arr[i]] = 1 + before_a;
            ans = max(ans, mp[arr[i]]);
        }

        return ans;
    }
};
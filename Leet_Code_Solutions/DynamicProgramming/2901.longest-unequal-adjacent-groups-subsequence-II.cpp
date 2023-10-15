class Solution
{
public:
    int calculate_hamDist(string &a, string &b)
    {
        int count = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] != b[i])
            {
                count++;
            }
        }

        return count;
    }

    vector<string> getWordsInLongestSubsequence(int n, vector<string> &words, vector<int> &groups)
    {
        // Concept of Longest Increasing Subsequence. (LIS).
        // Dynamic Programming.

        // What we had to do was for every index ending at i, we had to check the
        // previous index j where we could add the current the index.
        // Out of which we would the largest subsequence which holds all the conditions
        // as well.

        // So we would do this for every index i.
        // We would also make a maxlength variable to store the maximum length.
        // After that we find the maxLength string in dp and return it.

        // How to reduce the time complexity.
        // We can use the concept of parent making.
        // vector<vector<string>> dp(n); // stores the longest subsequence ending at i.

        // for(int i = 0;i < n;i++){
        //     dp[i] = {words[i]};
        // }

        // // Maxlength variable to store the maxlength.
        // int maxLength = 1;
        // for(int i = 1;i < n;i++){
        //     for(int j = i - 1;j >= 0;j--){
        //         // for the current index we will check every index before it.
        //         // where it could be attached and form a valid subsequence going ahead.

        //         if(groups[i] != groups[j] && words[i].size() == words[j].size()){
        //             int hamDistance = calculate_hamDist(words[i], words[j]);
        //             // All the conditons are satisfied.
        //             // We can add it to the current sequence.
        //             if(hamDistance == 1){
        //                 if(dp[i].size() < dp[j].size() + 1){
        //                     // time complexity is getting high.
        //                     dp[i] = dp[j];
        //                     dp[i].push_back(words[i]);
        //                     maxLength = max(maxLength, int(dp[i].size()));
        //                 }
        //             }
        //         }
        //     }
        // }
        // vector<string> ans;
        // for(int i = 0;i < n;i++){
        //     if(dp[i].size() == maxLength){
        //         ans = dp[i];
        //     }
        // }

        // return ans;

        // Using LIS and Parent Making.

        // lis -> lis[i] indicates the longest increasing subsequence till index i.
        // parent[i] -> indicates the parent[i] where it was part
        vector<int> lis(n, 1);
        vector<int> parent(n);

        int max_index = 0;
        vector<string> res;

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            for (int j = i - 1; j >= 0; j--)
            {
                if (groups[i] != groups[j] && words[i].size() == words[j].size() && calculate_hamDist(words[i], words[j]) == 1)
                {
                    if (lis[j] + 1 > lis[i])
                    {
                        parent[i] = j;
                        lis[i] = lis[j] + 1;
                    }
                }
            }

            if (lis[i] > lis[max_index])
            {
                max_index = i;
            }
        }

        int curr = max_index;
        while (curr != parent[curr])
        {
            res.push_back(words[curr]);
            curr = parent[curr];
        }

        res.push_back(words[curr]);

        reverse(res.begin(), res.end());

        return res;
    }
};

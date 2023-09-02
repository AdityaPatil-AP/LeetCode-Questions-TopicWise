class Solution
{
public:
    int minExtraChar(string s, vector<string> &dictionary)
    {
        unordered_map<string, bool> isPresent;

        for (int i = 0; i < dictionary.size(); i++)
        {
            isPresent[dictionary[i]] = true;
        }

        int n = s.size();

        vector<int> dp(n, 1e9);

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                string curr = s.substr(i, j - i + 1);
                // If the word is present.
                if (isPresent[curr])
                {
                    if (i - 1 < 0)
                    {
                        dp[j] = min(dp[j], 0);
                    }
                    else
                        dp[j] = min(dp[j], dp[i - 1]);
                }
                // If the word is not present.
                if (i - 1 < 0)
                    dp[j] = min(dp[j], (j - i + 1));
                else
                    dp[j] = min(dp[j], dp[i - 1] + (j - i + 1));
            }
        }

        return dp[n - 1];
    }
};

// Using Trie.

// class Solution {
// public:
//     int minExtraChar(string s, vector<string>& dictionary) {
//         unordered_map<string, bool> isPresent;

//         for(int i = 0;i < dictionary.size();i++){
//             isPresent[dictionary[i]] = true;
//         }

//         int n = s.size();

//         vector<int> dp(n, 1e9);

//         for(int i = 0;i < n;i++){
//             for(int j = i;j < n;j++){
//                 string curr = s.substr(i, j - i + 1);
//                 // If the word is present.
//                 if(isPresent[curr]){
//                     if(i - 1 < 0){
//                         dp[j] = min(dp[j], 0);
//                     }
//                     else
//                         dp[j] = min(dp[j], dp[i - 1]);
//                 }
//                 // If the word is not present.
//                 if(i - 1 < 0)
//                     dp[j] = min(dp[j], (j - i + 1));
//                 else
//                     dp[j] = min(dp[j], dp[i-1] + (j - i + 1));
//             }
//         }

//         return dp[n - 1];
//     }
// };

class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
    bool is_word;
};

class Solution
{
public:
    int minExtraChar(string s, vector<string> &dictionary)
    {
        int n = s.length();
        auto root = buildTree(dictionary);
        unordered_map<int, int> memo;

        function<int(int)> dp = [&](int start)
        {
            if (start == n)
            {
                return 0;
            }

            if (memo.count(start))
            {
                return memo[start];
            }

            // To count this character as a left over character
            // move to index 'start + 1'.
            int ans = dp(start + 1) + 1;
            TrieNode *node = root;
            for (int end = start; end < n; end++)
            {
                char c = s[end];
                if (node->children.find(c) == node->children.end())
                {
                    break;
                }
                node = node->children[c];

                if (node->is_word)
                {
                    ans = min(ans, dp(end + 1));
                }
            }

            return memo[start] = ans;
        };

        return dp(0);
    }

    TrieNode *buildTree(vector<string> &dictionary)
    {
        auto root = new TrieNode();
        for (auto &word : dictionary)
        {
            auto node = root;
            for (auto &c : word)
            {
                if (node->children.find(c) == node->children.end())
                {
                    node->children[c] = new TrieNode();
                }
                node = node->children[c];
            }
            node->is_word = true;
        }

        return root;
    }
};
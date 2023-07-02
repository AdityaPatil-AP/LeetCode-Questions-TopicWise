class TrieNode
{
public:
    int count;
    map<int, TrieNode *> children;

public:
    TrieNode()
    {
        count = 0;
    }
};

class Trie
{
    TrieNode *trie;

public:
    Trie()
    {
        trie = new TrieNode();
    }

    void insert(vector<int> arr)
    {
        // dummy variable.
        TrieNode *myTrie = trie;
        for (auto elem : arr)
        {
            if (myTrie->children.find(elem) == myTrie->children.end())
            {
                myTrie->children[elem] = new TrieNode();
            }
            myTrie = myTrie->children[elem];
        }

        myTrie->count += 1;
    }

    int search(vector<int> arr)
    {
        TrieNode *myTrie = trie;
        for (auto elem : arr)
        {
            if (myTrie->children.find(elem) == myTrie->children.end())
            {
                return 0;
            }
            myTrie = myTrie->children[elem];
        }

        return myTrie->count;
    }
};

class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        // 1) Brute Force.

        // 2) Using Hashmap.
        // Storing collection of columns with respect to their frequencies.

        // Arrays typically are not used as keys.
        // Convert the array into string and then map them.

        //         int n = grid.size();
        //         unordered_map<string, int> colFreq;

        //         for(int j = 0;j < n;j++){
        //             string col;
        //             for(int i = 0;i < n;i++){
        //                 col += (to_string(grid[i][j]) + ",");
        //             }
        //             colFreq[col]++;
        //         }

        //         // Retrieve them to find the matching (row, column) pairs.

        //         int ans = 0;

        //         for(int i = 0;i < n;i++){
        //             string row;
        //             for(int j = 0;j < n;j++) row += (to_string(grid[i][j]) + ",");
        //             ans += colFreq[row];
        //         }

        //         return ans;

        // Using Trie.

        int ans = 0;
        int n = grid.size();

        // Create a Trie.
        Trie *myTrie = new Trie();

        // Create a Trie using the grid rows as our key.
        for (int i = 0; i < n; i++)
        {
            myTrie->insert(grid[i]);
        }

        // Find the matching rows for the given columns.
        for (int j = 0; j < n; j++)
        {
            vector<int> arr;
            for (int i = 0; i < n; i++)
            {
                arr.push_back(grid[i][j]);
            }
            ans += myTrie->search(arr);
        }

        return ans;
    }
};
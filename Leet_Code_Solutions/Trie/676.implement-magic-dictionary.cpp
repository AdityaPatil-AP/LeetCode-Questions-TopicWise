// Using UnorderedMap.

class MagicDictionary
{
public:
    unordered_map<int, vector<string>> mp;
    MagicDictionary()
    {
    }

    void buildDict(vector<string> dict)
    {
        for (auto str : dict)
        {
            mp[str.size()].push_back(str);
        }
    }

    bool found(string &str, string &searchWord)
    {
        int diff = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] != searchWord[i])
                diff++;
        }
        return (diff == 1);
    }

    bool search(string searchWord)
    {
        int n = searchWord.size();
        for (auto str : mp[n])
        {
            if (found(str, searchWord))
            {
                return true;
            }
        }
        return false;
    }
};

struct Node
{
    Node *links[26];
    bool isLeaf;

    Node()
    {
        isLeaf = false;
        for (int i = 0; i < 26; i++)
        {
            links[i] = NULL;
        }
    }
};

// Using Trie.

class MagicDictionary
{
private:
    Node *root;

public:
    MagicDictionary()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->links[word[i] - 'a'] == NULL)
            {
                node->links[word[i] - 'a'] = new Node();
            }

            node = node->links[word[i] - 'a'];
        }

        node->isLeaf = true;
    }

    void buildDict(vector<string> dict)
    {
        for (auto str : dict)
        {
            insert(str);
        }
    }

    bool search(string searchWord)
    {
        Node *node = root;
        return search(0, searchWord, false, node);
    }

    bool search(int index, string &word, bool change, Node *node)
    {
        if (index == word.size())
        {
            if (node->isLeaf && change)
                return true;
            return false;
        }

        if (!change)
        {
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                if (ch == word[index])
                {
                    continue;
                }
                if (node->links[ch - 'a'] != NULL)
                {
                    if (search(index + 1, word, true, node->links[ch - 'a']))
                    {
                        return true;
                    }
                }
            }
        }
        if (!node->links[word[index] - 'a'])
        {
            return false;
        }
        return search(index + 1, word, change, node->links[word[index] - 'a']);
    }
};
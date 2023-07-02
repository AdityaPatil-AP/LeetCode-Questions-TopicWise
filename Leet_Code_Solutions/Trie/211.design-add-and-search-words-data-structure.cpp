struct Node
{
    Node *links[26];
    // Flag denotes that for the current reference trie some word ends here.
    bool flag = false;

    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }
};

class WordDictionary
{
private:
    Node *root;

public:
    WordDictionary()
    {
        root = new Node();
    }

    void addWord(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            // if the current character has no reference trie, then we have to create one for it.
            // Now this code looks redundant, so write a function for it, i.e. containsKey.
            if (!node->containsKey(word[i]))
            {
                // Then we have to put a reference trie for it.
                node->put(word[i], new Node());
            }
            // now shift to the reference trie;
            // write a function to get the reference trie as well.
            node = node->get(word[i]);
        }

        // Now the word have ended and we are at the last reference trie.
        // Mark it as true to represent the end of the current word.
        node->setEnd();
    }

    bool search(string word)
    {
        // Searching part is similar.
        return search(word, root, 0);
    }

    bool search(string &word, Node *root, int start)
    {
        Node *node = root;
        for (int i = start; i < word.size(); i++)
        {
            if (word[i] == '.')
            {
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    if (node->containsKey(ch))
                    {
                        if (search(word, node->get(ch), i + 1))
                        {
                            return true;
                        }
                    }
                }
                return false;
            }
            if (!node->containsKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

struct Node
{
    unordered_map<char, Node *> mp;
    // Flag denotes that for the current reference trie some word ends here.
    bool flag = false;

    bool containsKey(char ch)
    {
        return !((mp[ch]) == NULL);
    }

    void put(char ch, Node *node)
    {
        mp[ch] = node;
    }

    Node *get(char ch)
    {
        return mp[ch];
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }
};

class WordDictionary
{
private:
    Node *root;

public:
    WordDictionary()
    {
        root = new Node();
    }

    void addWord(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            // if the current character has no reference trie, then we have to create one for it.
            // Now this code looks redundant, so write a function for it, i.e. containsKey.
            if (!node->containsKey(word[i]))
            {
                // Then we have to put a reference trie for it.
                node->put(word[i], new Node());
            }
            // now shift to the reference trie;
            // write a function to get the reference trie as well.
            node = node->get(word[i]);
        }

        // Now the word have ended and we are at the last reference trie.
        // Mark it as true to represent the end of the current word.
        node->setEnd();
    }

    bool search(string word)
    {
        // Searching part is similar.
        Node *curr = root;
        return search(word, curr, 0);
    }

    bool search(string &word, Node *root, int start)
    {
        if (start == word.size())
        {
            return root->isEnd();
        }

        if (word[start] == '.')
        {
            for (auto it : root->mp)
            {
                if (search(word, it.second, start + 1))
                {
                    return true;
                }
            }
            return false;
        }

        if (!root->containsKey(word[start]))
        {
            return false;
        }

        return search(word, root->get(word[start]), start + 1);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
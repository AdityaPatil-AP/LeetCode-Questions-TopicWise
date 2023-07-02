#include <bits/stdc++.h>
using namespace std;

std::vector<std::string> getWordsFromString(const std::string &text)
{
    std::istringstream iss(text);
    std::vector<std::string> words;
    std::string word;

    while (iss >> word)
    {
        words.push_back(word);
    }

    return words;
}

vector<string> getWordsFromString(string &text)
{
    istringstream iss(text);
    vector<string> words;
    string word;

    while (iss >> word)
    {
        words.push_back(word);
    }

    return words;
}

vector<string> helper(string &text, int k)
{
    vector<string> words = getWordsFromString(text);

    map<string, int> mp;
    for (auto word : words)
    {
        mp[word]++;
    }

    vector<string> ans;
    for (auto word : words)
    {
        if (mp[word] >= k)
        {
            ans.push_back(word);
            mp[word] = 0;
        }
    }

    return ans;
}

int main()
{
    // string text = "hello the a a the the is ohkay ohkay hello";
    // vector<string> ans = helper(text, 2);

    // for (auto i : ans)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    cout << (1 << 0) << endl;
    return 0;
}
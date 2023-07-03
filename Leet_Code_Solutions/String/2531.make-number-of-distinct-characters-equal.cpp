class Solution
{
public:
    bool isItPossible(string word1, string word2)
    {
        // Brute Force Appraoch.
        // If we swap every ith and jth index, and calculate unique elements
        // and check if they are equal.

        // unordered_map<char, int> mp1;
        // unordered_map<char, int> mp2;

        // for(int i = 0;i < word1.size();i++){
        //     for(int j = 0;j < word2.size();j++){
        //         swap(word1[i], word2[j]);
        //         for(int i = 0;i < word1.size();i++) mp1[word1[i]]++;
        //         for(int i = 0;i < word2.size();i++) mp2[word2[i]]++;

        //         if(mp1.size() == mp2.size()) return true;

        //         swap(word1[i], word2[j]);
        //         mp1.clear();
        //         mp2.clear();
        //     }
        // }

        // return false;

        // Optimised Approach.
        vector<int> w1(26, 0); // frequency for string 1.
        vector<int> w2(26, 0); // frequency for string 2.

        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n1 = 0; // keeps track of unique elements in string 1.
        int n2 = 0; // keeps track of unique elements in string 2.

        for (int i = 0; i < word1.size(); i++)
        {
            w1[word1[i] - 'a']++;
            if (w1[word1[i] - 'a'] == 1)
                n1++;
        }

        for (int i = 0; i < word2.size(); i++)
        {
            w2[word2[i] - 'a']++;
            if (w2[word2[i] - 'a'] == 1)
                n2++;
        }

        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                if (w1[i] != 0 && w2[j] != 0 && i != j)
                { // We are swapping (i + 'a' with j + 'a').
                    if (w2[j] == 1)
                        n2--; // If occurence of j in w2 is only 1, then after swapping unique element decrease by one.
                    if (w2[i] == 0)
                        n2++; // If occurence of i in w2 was 0, then by after swapping the unique element count will increase by one.
                    if (w1[j] == 0)
                        n1++;
                    if (w1[i] == 1)
                        n1--;
                    if (n1 == n2)
                        return true;
                    if (w2[j] == 1)
                        n2++;
                    if (w2[i] == 0)
                        n2--;
                    if (w1[j] == 0)
                        n1--;
                    if (w1[i] == 1)
                        n1++;
                }
                if (w1[i] != 0 && w2[j] != 0 && i == j)
                {
                    if (n1 == n2)
                        return true;
                }
            }
        }

        return false;

        // My Try : Wrong Answer : Some Test Cases Failed.
        // unordered_map<char, int> mp1, mp2;

        // for(auto i : word1) mp1[i]++;
        // for(auto i : word2) mp2[i]++;

        // // Non-redundant characters present in the string.
        // if(mp1.size() == word1.size() && mp2.size() == word2.size()){
        //     if(mp1.size() == mp2.size()) return true;
        //     return false;
        // }

        // // Redundant characters in the string present.
        // if(mp1.size() == mp2.size()) {
        //     return true;
        // }
        // // Redundant Characters but number of distinct character varies in both the strings.
        // if(abs((int)mp1.size() - (int)mp2.size()) == 1){
        //     for(auto it : mp1){
        //         if(it.first >= 2 && mp2.find(it.first) != mp2.end()){
        //             if(check(mp2, it.first)){
        //                 return true;
        //             }
        //         }
        //     }

        //     return false;
        // }

        // // It is also possible to make number of distinct characters equal when the
        // // current difference between them is 2.
        // if(abs((int)mp1.size() - (int)mp2.size()) == 2){
        //     for(auto it : mp1){
        //         if(it.first >= 2 && mp2.find(it.first) != mp2.end()){
        //             if(check1(mp2, it.first)){
        //                 return true;
        //             }
        //         }
        //     }

        //     return false;
        // }

        // return false;
    }

    // Check in the map, that apart from curr character is there any character which have
    // one time appearance only.
    bool check1(unordered_map<char, int> &mp, char curr)
    {
        for (auto it : mp)
        {
            if (it.first != curr && it.second == 1)
            {
                return true;
            }
        }

        return false;
    }

    // Check if map has another redundant character apart from this one.

    bool check(unordered_map<char, int> &mp, char curr)
    {
        for (auto it : mp)
        {
            if (it.first != curr)
            {
                if (it.second >= 2)
                    return true;
            }
        }

        return false;
    }
};
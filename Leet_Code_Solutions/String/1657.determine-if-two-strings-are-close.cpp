class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        // Brute Force.
        // if(word1.size() != word2.size()){
        //     return false;
        // }
        // map<char, int> mp1;
        // map<char, int> mp2;
        // for(int i = 0;i < word1.size();i++){
        //     mp1[word1[i]]++;
        // }
        // for(int i = 0;i < word2.size();i++){
        //     mp2[word2[i]]++;
        // }
        // vector<int> freq1;
        // vector<int> freq2;
        // for(auto x : mp1){
        //     if(mp2.find(x.first) != mp2.end()){
        //         freq1.push_back(x.second);
        //         freq2.push_back(mp2[x.first]);
        //     }
        //     else {
        //         return false;
        //     }
        // }

        // sort(freq1.begin(), freq1.end());
        // sort(freq2.begin(), freq2.end());
        // if(freq1 == freq2){
        //     return true;
        // }
        // return false;

        // Improved solution by using vector<int> of size 26 and set.
        // To store the frequencies of all characters for both the word.
        vector<int> freq1(26, 0), freq2(26, 0);

        // Now first we need to make sure that elements present in word1
        // are all present in element 2.

        for (auto i : word1)
        {
            freq1[i - 'a']++;
        }

        for (auto i : word2)
        {
            // checking if this character is present in word1 as well or not.
            // Because transform can only be applied for the characters present
            // in the word1.
            if (freq1[i - 'a'] == 0)
            {
                return false;
            }

            freq2[i - 'a']++;
        }

        sort(begin(freq1), end(freq1));
        sort(begin(freq2), end(freq2));

        return (freq1 == freq2);
    }
};
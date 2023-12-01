class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string cum1, cum2;

        for(int i = 0;i < word1.size();i++) cum1 += word1[i];
        for(int i = 0;i < word2.size();i++) cum2 += word2[i];

        return (cum1 == cum2);
    }
};
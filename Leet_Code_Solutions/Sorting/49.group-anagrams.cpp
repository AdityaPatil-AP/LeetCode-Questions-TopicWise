class Solution {
public:
    // Using un_ordered map and sort function
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // unordered map of original string to all the anagrams present in the strs array.
        unordered_map<string, vector<string>> umap;
        // Storing all the anagrams corresponding to initial anagram(which is sorted).
        for(auto i : strs){
            string temp = i;
            sort(temp.begin(), temp.end());
            umap[temp].push_back(i);
        }
        // Now taking those vector<strings> and pushing it into our res array.
        vector<vector<string>> res;
        for(auto i : umap){
            res.push_back(i.second);
        }
        return res;
    }
};
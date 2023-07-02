class Solution {
public:
    string oddString(vector<string>& words) {
        map<vector<int>, pair<int, string>> mp;
        for(int i = 0;i < words.size();i++){
            vector<int> difference;
            for(int j = 0;j < words[i].size() - 1;j++){
                difference.push_back((int)words[i][j + 1] - (int)words[i][j]);
            }
            if(mp[difference].first == 0){
                mp[difference].second = words[i];
            }
            mp[difference].first++;
        }
        for(auto it : mp){
            if(it.second.first == 1){
                return it.second.second;
            }
        }
        return "0";
    }
};
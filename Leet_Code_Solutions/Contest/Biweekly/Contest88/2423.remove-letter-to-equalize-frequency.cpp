class Solution {
public:
    bool equalFrequency(string word) {
        map<char, int> mp;
        int n = word.size();
        for(int i = 0;i < n;i++){
            mp[word[i]]++;
        }
        map<int, int> nmp;
        for(auto i : mp){
            nmp[i.second]++;
        }
        if(nmp.size() == 1){
            int element;
            int freq;
            for(auto i : nmp){
                element = i.first;
                freq = i.second;
            }
            if(element == 1 || (freq == 1)){
                return true;
            }
            else{
                return false;
            }
        }
        if(nmp.size() > 2) return false;
        vector<pair<int, int>> ans;
        for(auto i : nmp){
            ans.push_back({i.first, i.second});
        }
        sort(ans.begin(), ans.end());
        if((1 + ans[0].first) == ans[1].first &&  ans[1].second == 1) return true;
        if((1 + ans[0].first) == ans[1].first &&  (ans[0].second == 1 && ans[0].first == 1)) return true;
        return false;
    }
};
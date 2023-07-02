class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        // sum, views, id
        map<string, pair<long long int,long long int>> mp;
        int n = creators.size();
        for(int i = 0;i < n;i++){
            if(mp.find(creators[i]) == mp.end()){
                mp[creators[i]].first = views[i];
                mp[creators[i]].second = i; 
            }
            else {
                mp[creators[i]].first += views[i];
                if(views[(mp[creators[i]].second)] == views[i] && ids[i] < ids[(mp[creators[i]].second)]){
                    mp[creators[i]].second = i;
                }
                else if(views[(mp[creators[i]].second)] < views[i]){
                    mp[creators[i]].second = i;
                }
            }
        }
        vector<vector<string>> ans;
        long long int maxViews = INT_MIN;
        for(auto it : mp){
            if(ans.size() == 0){
                ans.push_back({it.first, ids[it.second.second]});
                maxViews = max(maxViews, it.second.first);
            }
            else if(it.second.first > maxViews){
                ans.clear();
                ans.push_back({it.first, ids[it.second.second]});
                maxViews = max(maxViews, it.second.first);
            }
            else if(it.second.first == maxViews){
                ans.push_back({it.first, ids[it.second.second]});
            }
        }                                            
        return ans;                                                         
    }
};
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi = *max_element(candies.begin(), candies.end());
        
        vector<bool> ans(candies.size(), false);
        
        for(int i = 0;i < candies.size();i++){
            if(candies[i] + extraCandies >= maxi){
                ans[i] = true;
            }
        }
        
        return ans;
    }
};
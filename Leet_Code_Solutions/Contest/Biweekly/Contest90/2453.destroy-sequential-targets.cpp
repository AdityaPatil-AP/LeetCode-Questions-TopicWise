class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> mod(n, 0);
        map<int, int> mp;
        for(int i = 0;i < n;i++){
            mod[i] = nums[i] % space;
            mp[nums[i] % space]++;
        }
        int maxFreq = 0;
        int ans = nums[0];
        for(int i = 0;i < n;i++){
            if(mp[nums[i]%space] > maxFreq){
                ans = nums[i];
                maxFreq = mp[nums[i]%space];
            }
        }
        return ans;
    }
};
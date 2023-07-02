class Solution {
public:
    
    int longestArithSeqLength(vector<int>& nums) {
        // Key Point
        
        // 1) Longest Arithmetic Subsequence ending at i with difference equal to k. (-1000 to 1000.).
        
        // 2) Instead of using a map which gives TLE. You can use a vector of suitable size.
        
        int ans = 2;
        int n = nums.size();
        vector<vector<int>> mp(n, vector<int>(2000, 0));
        // unordered_map<int, unordered_map<int, int>> mp;// for every index storing the longest arithmetic subsequence for the difference which 
        // occurs with the previous elements in the array.
        
        for(int i = 1;i < n;i++){
            for(int j = 0;j < i;j++){
                int diff = nums[i] - nums[j] + 1000;
                mp[i][diff] = (1 + mp[j][diff]);
                ans = max(ans, mp[i][diff] + 1);
            }
        }
        
        return ans;

    }
};
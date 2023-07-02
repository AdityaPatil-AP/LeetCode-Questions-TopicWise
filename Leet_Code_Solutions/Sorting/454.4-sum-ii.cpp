class Solution {
public:
    // We are going to use un_ordered map and using the concept of pair sums.
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        // Will store the count of tuples
        int count = 0;
        // Will store the pair sums and their frequencies in the map.
        unordered_map<int, int> mp;
        
        // Traversing part 1 and storing the pair sums and their corresponding frequencies.
        for(auto &it1 : nums1){
            for(auto &it2 : nums2){
                mp[it1 + it2]++;
            }
        }
        
        // Now we will check if for the pair sum = (it3 + it4) if (-sum) exist in the map or not
        // If yes then we increment the count by the frequency of that pair sum.
        
        // Traversing Part 2
        for(auto &it3 : nums3){
            for(auto &it4 : nums4){
                if(mp.count(-(it3 + it4))){
                    count += mp[(-(it3 + it4))];
                }
            }
        }
        
        return count;
    }
};
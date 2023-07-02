class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
       // int n1 = nums1.size(), n2 = nums2.size();
       //  if(n1 % 2 == 0 && n2 % 2== 0){
       //      return 0;
       //  }
       //  else if(n1 % 2 == 1 && n2 %  2 == 0){
       //      int ans = 0;
       //      for(int i = 0;i < n2;i++){
       //          ans ^= nums2[i];
       //      }
       //      return ans;
       //  }
       //  else if(n2 % 2 == 1 && n1 % 2 == 0){
       //      int ans = 0;
       //      for(int i = 0;i < n1;i++){
       //          ans ^= nums1[i];
       //      }
       //      return ans;
       //  }
       //  else{
       //      int ans = 0;
       //      for(int i = 0;i < n1;i++){
       //          ans ^= nums1[i];
       //      }
       //      for(int i = 0;i < n2;i++){
       //          ans ^= nums2[i];
       //      }
       //      return ans;
       //  }
        int x = 0, y = 0;
        for(auto i : nums1){
            x ^= i;
        }
        for(auto j : nums2){
            y ^= j;
        }
        return (nums1.size() % 2 * y) ^ (nums2.size() % 2 * x);
    }
};
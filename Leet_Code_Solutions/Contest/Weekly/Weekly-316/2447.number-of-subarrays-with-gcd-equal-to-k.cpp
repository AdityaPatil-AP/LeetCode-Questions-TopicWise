class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int count = 0;
        for(int i = 0;i < nums.size();i++){
            int num = nums[i];
            for(int j = i;j < nums.size();j++){
                if((__gcd(nums[j], num)) == k){
                    // cout << i << " " << j << endl;
                    num = __gcd(nums[j], num);
                    count++;
                }
                else if(__gcd(nums[j], num) < k){
                    break;
                }
                else{
                    num = __gcd(nums[j], num);
                    continue;
                } 
            }
        }
        return count;
    }
};
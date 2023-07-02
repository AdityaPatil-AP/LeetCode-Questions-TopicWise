class Solution {
public:
    // Comparator.
    static bool comp(int &num1, int &num2){
        if(num1 % 2 == 1 || num2 % 2 == 1){
            if(num1 > num2 && num1&1 && num2&1) return false;
            if((num1&1) == 0 && num2&1) return false;
            return true;
        }
        else if(num1 < num2) return true;
        return false;
    }
    
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        long long ans = 0;
        sort(nums.begin(), nums.end(), comp);
        sort(target.begin(), target.end(), comp);
        for(int i = 0;i < nums.size();i++){
            if(nums[i] - target[i] >= 0){
                ans += abs(nums[i] - target[i])/2;
            }
        }
        return ans;
    }
};
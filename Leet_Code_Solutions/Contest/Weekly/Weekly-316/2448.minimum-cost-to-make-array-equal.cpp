class Solution {
public:
    long long getCost(vector<int>&nums, vector<int>&cost, int mid){
        long long sum = 0;
        for(int i= 0;i < nums.size();i++){
            long long change = abs(nums[i] - mid);
            sum += (change * cost[i]);
        }
        return sum;
    }
    
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int low = 1, high = 1e6;
        while(low <= high){
            int mid = low + (high - low)/2;
            long long sum1 = getCost(nums, cost, mid);
            long long sum2 = getCost(nums, cost, mid + 1);
            long long sum3 = getCost(nums, cost, mid - 1);
            if(sum1 <= sum2 && sum1 <= sum3) return sum1;
            else if(sum1 > sum2){
                low = mid + 1;
            }
            else if(sum1 > sum3){
                high = mid - 1;
            }
        }
        return 0;
    }
};
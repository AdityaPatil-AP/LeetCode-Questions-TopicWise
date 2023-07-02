class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // Least capacity weight capacity can be 1 to 500.
        // sort(weights.begin(), weights.end());
        int l = 1, r = 1e8;
        int ans = 1;
        while(l <= r){
            int mid = (l + (r - l)/2);
            if(isPossible(mid, weights, days)){
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        
        return ans;
    }
    
    bool isPossible(int m, vector<int> &weights, int days){
        int requiredDays = 0;
        int currWeight = 0;
        for(auto i : weights){
            if(currWeight + i > m){
                requiredDays++;
                currWeight = 0;
            }
            if(i > m) return false;
            currWeight += i;
        }
        if(currWeight > 0) requiredDays++;
        return (requiredDays <= days);
    }
};
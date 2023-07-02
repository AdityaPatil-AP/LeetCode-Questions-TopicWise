class Solution {
public:
    int arrangeCoins(int n) {
        int low = 1, high = n;
        int ans;
        while(low <= high){
            long long int mid = low + (high - low)/2;
            // We will be updating our ans continously until this condition is met. and we 
            // increase our low to mid + 1, to check whether a bigger mid exists for which
            // this condition is 
            if((mid*(mid + 1))/2 <= n){
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
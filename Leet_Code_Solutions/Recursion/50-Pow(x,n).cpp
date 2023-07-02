class Solution {
public:
    // double helper(double x, int n){
    //     if(n == 0){
    //         return 1;
    //     }
    //     double res1 = myPow(x, n/2);
    //     double ans;
    //     if(n % 2 == 0){
    //         ans = res1 * res1;
    //     }
    //     else{
    //         ans = x * res1 * res1;
    //     }
    //     return ans;
    // }
    double myPow(double x, int n) {
        // first Try
        // return (n < 0)? (1/helper(x,abs(n))):helper(x, n);
        
        // Iterative appraoch using Binary Exponentiation
        double res1 = 1;
        while(n != 0){
            if(n % 2 != 0) (n > 0) ? res1 = res1 * x : res1/x;
            x = x * x;
            n /= 2;
        }
        return res1;
    }
};
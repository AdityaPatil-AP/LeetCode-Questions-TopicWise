class Solution {
public:
    long calcCoeff(int n, int k){
        long res = 1;
        for(int i = 0;i < k;i++){
            res *= (n - i);
            res /= (i + 1);
        }
        return res;
    }
    
    long numTrees(int n) {
        // Recursive Approach - TLE
        // int result = 0;
        // if(n == 0 || n == 1){
        //     return 1;
        // }
        // for(int i = 0; i < n;i++){
        //     result += numTrees(n - i - 1) * numTrees(i);
        // }
        // return result;
        
        // Tabulation Way use DP
        // vector<int> vec(n+1, 0);
        // vec[0] = vec[1] = 1;
        // for(int i = 2;i <= n;i++){
        //     for(int j = 0;j < i;j++){
        //         vec[i] += vec[j] * vec[i - j - 1];
        //     }
        // }
        // return vec[n];
        // Time Complexity : O(n^2);
        // Space Complexity : O(n);
        
        // Using Binomial Coefficient
        return calcCoeff(2 * n, n)/ (n + 1);
        // Time Complexity : O(n);
        // Space Complexity : O(1);
    }
};
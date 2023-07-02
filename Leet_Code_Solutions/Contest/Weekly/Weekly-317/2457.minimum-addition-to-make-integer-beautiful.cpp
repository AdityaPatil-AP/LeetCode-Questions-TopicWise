class Solution {
public:
    int sumOfDigits(long long int num){
        long long int temp = num;
        int sum = 0;
        while(temp > 0){
            sum += temp % 10;
//             if(sum > target){
                
//             }
            temp /= 10;
        }
        return sum;
    }
    
    long long makeIntegerBeautiful(long long n, int target) {
        int m = 0;
        long long int temp = n;
        long long int currnum;
        currnum = n;
        while(true){
            if(m != 0){
                long long int base = pow(10, m);
                while(currnum % base == 0){
                    m++;
                    base = pow(10, m);
                }
                currnum -= currnum % base;
                currnum += base;
            }
            if(sumOfDigits(currnum) <= target){
                return currnum - temp;
            }
            m++;
        }
    }
};
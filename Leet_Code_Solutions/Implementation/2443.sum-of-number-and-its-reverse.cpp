class Solution {
public:
    int reverse(int n){
        int temp = 0;
        while(n > 0){
            int k = n % 10;
            temp = (temp * 10) + k;
            n /= 10;
        }
        return temp;
    }
    
    bool sumOfNumberAndReverse(int num) {
        int numDigits = 0;
        int temp = num;
        // int k = log10(num);
        // if(num == 0) return true;
        for(int i = 0;i <= num;i++){
            if((i + reverse(i)) == num){
                return true;
            }
        }
        return false;
    }
};
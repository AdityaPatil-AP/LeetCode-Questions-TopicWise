class Solution {
public:
    int subtractProductAndSum(int n) {
        // 1)
        // int p = 1;
        // int s = 0;
        // while(n > 0){
        //     int k = n % 10;
        //     n /= 10;
        //     s += k;
        //     p *= k;
        // }
        // return p - s;
        
        // 2) 
        int prod=1,add=0; 
        string s=to_string(n);
        for(auto c:s){
            prod*=c-'0';
            add+=c-'0';
        }
        return prod-add;
    }
};

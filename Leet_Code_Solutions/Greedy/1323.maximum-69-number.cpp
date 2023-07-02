class Solution {
public:
    int maximum69Number (int num) {
        // Iterable Object.
        // string s = to_string(num);
        // for(int i = 0;i < s.size();i++){
        //     if(s[i] == '6'){
        //         s[i] = '9';
        //         break;
        //     }
        // }
        // num = stoi(s);
        // return num;
        
        // Using the Remainder Approach
        int i = 0, j = -1, temp = num;
        while(temp > 0){
            int k = temp % 10;
            if(k == 6){
                j = i;
            }
            i++;
            temp /= 10;
        }
        if(j == -1) return num; // It didn't had 6 as one of it's digits.
        return num + pow(10, j)*3;
    }
};
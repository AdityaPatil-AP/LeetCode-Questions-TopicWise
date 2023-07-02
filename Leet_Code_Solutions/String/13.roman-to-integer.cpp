class Solution {
public:
    map<char, int> mp;
    void init(){
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
     }
    int romanToInt(string s) {
        init();
        int ans = 0;
        for(int i = 0;i < s.size();i++){
            if(i < s.size() - 1 && mp[s[i]] < mp[s[i + 1]]){
                ans += (mp[s[i + 1]] - mp[s[i]]);
                i++;
            }
            else ans += mp[s[i]];
        }
        return ans;
    }
};
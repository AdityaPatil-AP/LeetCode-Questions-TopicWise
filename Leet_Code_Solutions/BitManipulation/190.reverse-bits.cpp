class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ans = 0;
        for(int i = 0;i < 32;i++){
            int mask = (n >> i) & 1;
            ans = ans | (mask << (31 - i));
        }
        return ans;
    }
};
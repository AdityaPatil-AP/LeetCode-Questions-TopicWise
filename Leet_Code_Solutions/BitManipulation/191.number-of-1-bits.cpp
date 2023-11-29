class Solution {
public:
    int hammingWeight(uint32_t n) {
        // Using builtin function.. - for count the number of set bits
        // or bits with value 1.
        return __builtin_popcount(n);
        
        // Using right shift operator(>>).
        // We are checking all the bits of the number from right position.
        // int count = 0;
        // while(n > 0){
        //     if(n & 1) count++;
        //     n >>= 1; // shift all bit in right by one position.
        // }
        // return count;
        
        // More Optimised solution, number of iterations 
        // will be equal to number of set bits.
        // int count = 0; // number of set bit.
        // while(n > 0){ // Iterate all bits are traversed.
        //     ++count;
        //     n &= (n - 1); // change the first bit from right to 0.
        // }
        // return count;
        
        // Using inbuilt function bitset.
        // return bitset<32>(n).count();
    }
};
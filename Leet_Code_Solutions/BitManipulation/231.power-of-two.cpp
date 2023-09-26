class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        // String Representation.
        // Fetch the string represenation of n.
        // and count the number of 1's in it. If it's equal to 1.
        // Then return true or else false.

        // Using Bit Manipulation.
        // if(n < 0){
        //     return false;
        // }
        // int countOne = 0;
        // for(int i = 0;i < 32;i++){
        //     if((n >> i) & 1){
        //         countOne++;
        //     }
        // }

        // return (countOne == 1);

        // Using bit Manipulation.
        // if(n <= 0) return false;
        // return !(n & (n - 1));

        // Builtin function.
        if (n <= 0)
            return false;
        int bits = __builtin_popcount(n);

        return (bits == 1);

        // Remainder.
        if (n <= 0)
            return false;

        while (n % 2 == 0)
            n /= 2;

        return (n == 1);
    }
};
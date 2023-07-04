class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        //         // We can easily do this question using map.

        //         // But to do in O(1) space complexity, we can implement it using bit manipulation.

        // unsigned int ans = 0;
        // long shift = 1;
        // for(int i = 0;i < 32;i++){
        //     // count the number of set bits at the ith position.
        //     int count = 0;
        //     for(int j = 0;j < nums.size();j++){
        //         if(nums[j]&shift) count++;
        //     }

        //     if(count % 3 == 1){
        //         ans = (ans | shift);
        //     }
        //     shift *= 2;
        // }

        // return ans;

        // Using Bit Manipulation and doing O(1) space.

        long int ans = 0;
        for (long long i = 0; i < 32; i++)
        {
            int count = 0;
            for (int j = 0; j < nums.size(); j++)
            {
                if (nums[j] & (1 << i))
                {
                    count++;
                }
            }

            if (count % 3 == 1)
            {
                ans = (ans | (1 << i));
            }
        }

        return ans;
    }
};
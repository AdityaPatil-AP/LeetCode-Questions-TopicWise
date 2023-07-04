class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        // Using map.
        // map<int, int> mp;
        // for(auto it : nums) mp[it]++;

        // vector<int> ans;
        // for(auto it : mp){
        //     if(it.second == 1) ans.push_back(it.first);
        // }

        // return ans;

        // Optimised using Bit Manipulation.
        // Find the xor of the whole array.
        long long number = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            number ^= nums[i];
        }

        // There is atleast one bit that is the different between
        // and b. Because they are distinct integers.
        long setBit = 1;
        while (true)
        {
            if (number & (setBit))
            {
                break;
            }
            setBit <<= 1;
        }

        // Let's say the setBit was present in b, then
        // we will take all the elements with that bit set for computation
        // of b. And Obviously that would not contain a. All other elements
        // will go to computation of a. Hence the repeated elements will cancel
        // out and we will be remaining with our Final Answers a and b.
        int firstAns = 0, secondAns = 0;
        for (int i = 0; i < n; i++)
        {
            if (setBit & (nums[i]))
            {
                firstAns ^= nums[i];
            }
            else
            {
                secondAns ^= nums[i];
            }
        }

        return {firstAns, secondAns};
    }
};
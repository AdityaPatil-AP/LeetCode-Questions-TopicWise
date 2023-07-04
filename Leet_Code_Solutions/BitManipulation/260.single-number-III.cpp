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
        long long number = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            number ^= nums[i];
        }

        long setBit = 1;
        while (true)
        {
            if (number & (setBit))
            {
                break;
            }
            setBit <<= 1;
        }

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
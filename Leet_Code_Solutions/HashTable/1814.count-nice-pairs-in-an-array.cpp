class Solution
{
public:
    int countNicePairs(vector<int> &nums)
    {
        // nums[i] + rev[nums[j]] == nums[j] + rev(nums[i]).

        // i < j.

        // In this case, x = nums[i] and y = nums[j].
        // Rearranging the equation, x - rev(x) == y - rev(y).

        // For a given number num, we are interested in (num - rev(num)).

        vector<int> arr;

        for (int i = 0; i < nums.size(); i++)
        {
            arr.push_back(nums[i] - rev(nums[i]));
        }

        unordered_map<int, int> mp;

        int ans = 0;

        int mod = 1e9 + 7;

        for (int num : arr)
        {
            ans = (ans + mp[num]) % mod;

            mp[num]++;
        }

        return ans;
    }

    int rev(int num)
    {
        // int result = 0;
        // while(num > 0){
        //     result = result * 10 + num % 10;
        //     num /= 10;
        // }

        // return result;

        string curr = to_string(num);
        reverse(curr.begin(), curr.end());

        return stoi(curr);
    }
};
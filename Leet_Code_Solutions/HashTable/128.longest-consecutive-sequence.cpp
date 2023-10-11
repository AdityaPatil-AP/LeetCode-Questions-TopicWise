class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        // last element
        map<int, int> mp;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            int curr = nums[i];

            if (mp.find(curr - 1) != mp.end())
            {
                mp[curr] = max(mp[curr], 1 + mp[curr - 1]);
            }
            else
            {
                mp[curr] = max(mp[curr], 1);
            }
        }

        int ans = 0;

        for (auto i : mp)
        {
            ans = max(ans, i.second);
        }

        return ans;
    }
};
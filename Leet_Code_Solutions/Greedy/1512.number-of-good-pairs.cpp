class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        int ans = 0;
        map<int, int> mp;
        for (int a : nums)
        {
            ans += (mp[a]++);
        }

        return ans;
    }
};
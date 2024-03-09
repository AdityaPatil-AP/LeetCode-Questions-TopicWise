class Solution
{
public:
    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {
        int ans = INT_MAX;

        map<int, int> mp1, mp2;

        for (auto it : nums1)
            mp1[it]++;

        for (auto it : nums2)
            mp2[it]++;

        for (auto it : nums1)
        {
            if (mp2.find(it) != mp2.end())
            {
                ans = it;
                break;
            }
        }

        return (ans == INT_MAX ? -1 : ans);
    }
};
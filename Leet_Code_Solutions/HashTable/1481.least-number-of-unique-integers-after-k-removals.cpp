class Solution
{
public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {
        map<int, int> mp;

        for (auto it : arr)
            mp[it]++;

        vector<int> v;

        for (auto it : mp)
        {
            v.push_back(it.second);
        }

        sort(v.begin(), v.end());

        int ans = mp.size();

        for (int i = 0; i < arr.size(); i++)
        {
            if (k >= v[i])
            {
                k -= v[i];
                ans--;
            }
            else
                break;
        }

        return ans;
    }
};
class Solution
{
public:
    vector<int> findArray(vector<int> &pref)
    {
        vector<int> ans;
        ans.push_back(pref[0]);
        for (int i = 1; i < pref.size(); i++)
        {
            ans.push_back(pref[i] ^ pref[i - 1]);
        }

        return ans;
    }
};

class Solution
{
public:
    vector<int> findArray(vector<int> &pref)
    {
        // Pref[i] -> arr[i] ^ arr[i - 1] ^ arr[i - 2] ^ arr[i - 3] ..

        int n = pref.size();
        vector<int> ans(n, 0);

        ans[0] = pref[0];

        for (int i = 1; i < n; i++)
        {
            ans[i] = (pref[i - 1] ^ pref[i]);
        }

        return ans;
    }
};
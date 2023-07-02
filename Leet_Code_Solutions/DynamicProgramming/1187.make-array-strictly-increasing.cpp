class Solution
{
public:
    // map<pair<int, int>, int> mp;
    int dp[2001][2001][2];

    int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2)
    {
        sort(arr2.begin(), arr2.end());
        memset(dp, -1, sizeof(dp));

        int ans = dfs(0, 0, true, arr1, arr2);

        return (ans < 2001) ? ans : -1;
    }

    int dfs(int index, int j, bool prev_arr1, vector<int> &arr1, vector<int> &arr2)
    {
        if (index == arr1.size())
        {
            return 0;
        }

        // if(mp.find(make_pair(index, prev)) != mp.end()){
        //     return mp[make_pair(index, prev)];
        // }

        if (dp[index][j][prev_arr1] != -1)
        {
            return dp[index][j][prev_arr1];
        }

        int cost = 1e9;
        int prev = prev_arr1 ? index == 0 ? INT_MIN : arr1[index - 1] : arr2[j];

        // leave and don't change.
        if (arr1[index] > prev)
        {
            cost = dfs(index + 1, j, true, arr1, arr2);
        }

        // Change.

        // 1) Either (arr1[i] < prev). Due to which we have to change arr1[i].
        // 2) or else we want a smaller value for this i in arr1. So we check for it in arr2.
        int idx = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();

        if (idx < arr2.size())
        {
            cost = min(cost, 1 + dfs(index + 1, idx, false, arr1, arr2));
        }

        return dp[index][j][prev_arr1] = cost;
    }
};
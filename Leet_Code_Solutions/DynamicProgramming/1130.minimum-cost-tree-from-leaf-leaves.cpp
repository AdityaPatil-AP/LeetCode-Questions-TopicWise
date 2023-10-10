class Solution
{
public:
    int mctFromLeafValues(vector<int> &arr)
    {
        map<pair<int, int>, int> mp;

        for (int i = 0; i < arr.size(); i++)
        {
            mp[{i, i}] = arr[i];

            for (int j = i + 1; j < arr.size(); j++)
            {
                mp[{i, j}] = max(arr[j], mp[{i, j - 1}]);
            }
        }

        int n = arr.size();

        return bottomUp(arr, mp, n);
    }

    int bottomUp(vector<int> &arr, map<pair<int, int>, int> &mp, int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // for(int i = 0;i <= n;i++){
        //     dp[i][i] = 0;
        // }

        for (int left = n - 1; left >= 0; left--)
        {
            for (int right = left + 1; right < n; right++)
            {
                int ans = INT_MAX;
                for (int i = left; i < right; i++)
                {
                    ans = min(ans, (mp[{left, i}]) * (mp[{i + 1, right}]) + dp[left][i] + dp[i + 1][right]);
                }
                dp[left][right] = ans;
            }
        }

        return dp[0][n - 1];
    }
};
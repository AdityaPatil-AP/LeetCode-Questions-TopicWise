class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<pair<int, int>> dp(n, make_pair(1, -1));

        dp[0] = make_pair(1, -1);

        int max = 1;
        int index = 0;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0)
                {
                    if (dp[i].first < dp[j].first + 1)
                    {
                        dp[i].second = j;
                        dp[i].first = dp[j].first + 1;
                    }
                }
            }

            if (dp[i].first > max)
            {
                index = i;
                max = dp[i].first;
            }
        }

        vector<int> ans;

        while (index != -1)
        {
            ans.push_back(nums[index]);
            index = dp[index].second;
        }

        return ans;
    }
};
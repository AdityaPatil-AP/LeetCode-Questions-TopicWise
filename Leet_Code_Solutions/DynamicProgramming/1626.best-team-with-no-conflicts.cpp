class Solution
{
public:
    static bool comp(pair<int, int> p1, pair<int, int> p2)
    {
        if (p1.first < p2.first)
            return true;
        if (p1.first == p2.first && p1.second <= p2.second)
            return true;
        return false;
    }

    int calculate(int index, vector<pair<int, int>> &group, int prev, vector<vector<int>> &dp)
    {
        int n = group.size();
        if (index == n)
            return 0;

        if (dp[index][prev] != -1)
        {
            return dp[index][prev];
        }

        // I will chose the index if i can
        int choose = INT_MIN, not_choose = INT_MIN;
        if (prev == n || (group[index].first == group[prev].first) || (group[index].second >= group[prev].second))
        {
            choose = group[index].second + calculate(index + 1, group, index, dp);
        }

        // or I will not choose the current player.
        not_choose = calculate(index + 1, group, prev, dp);

        return dp[index][prev] = max(choose, not_choose);
    }

    int bestTeamScore(vector<int> &scores, vector<int> &ages)
    {
        int n = scores.size();
        vector<pair<int, int>> group(n);
        for (int i = 0; i < n; i++)
        {
            group[i].first = ages[i];
            group[i].second = scores[i];
        }

        sort(group.begin(), group.end(), comp);
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        int ans = calculate(0, group, n, dp);
        return ans;
    }
};
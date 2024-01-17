class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        map<int, pair<int, int>> mp;

        for (auto it : matches)
        {
            int winner = it[0];
            int loser = it[1];

            mp[winner].first++;
            mp[loser].second++;
        }

        vector<int> winners1;
        vector<int> winners2;

        for (auto it : mp)
        {
            int total = it.second.first + it.second.second;

            if (total == it.second.first)
            {
                winners1.push_back(it.first);
            }
            if (total - 1 == it.second.first)
            {
                winners2.push_back(it.first);
            }
        }

        sort(winners1.begin(), winners1.end());
        sort(winners2.begin(), winners2.end());

        vector<vector<int>> ans;
        ans.push_back(winners1);
        ans.push_back(winners2);

        return ans;
    }
};
class Solution
{
public:
    string frequencySort(string s)
    {
        auto cmp = [](const pair<char, int> &a, const pair<char, int> &b)
        {
            return a.second > b.second;
        };

        priority_queue<pair<int, char>> pq;

        unordered_map<char, int> hm;

        for (auto it : s)
            hm[it]++;

        for (auto it : hm)
            pq.push({it.second, it.first});

        string ans = "";

        while (!pq.empty())
        {
            auto top = pq.top();

            ans.append(top.first, top.second);
            pq.pop();
        }

        return ans;
    }
};

class Solution
{
public:
    int numPairsDivisibleBy60(vector<int> &time)
    {
        for (auto &x : time)
        {
            x = x % 60;
        }
        sort(begin(time), end(time));

        long ans = 0;
        unordered_map<int, int> mp; // frequency map.
        for (auto x : time)
        {
            long count = (x == 0) ? mp[0] : mp.count(60 - x) ? mp[60 - x]
                                                             : 0;
            ans += count;
            mp[x]++;
        }

        return ans;
    }
};
class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        int n = spells.size();
        int m = potions.size();
        vector<int> ans(n);

        sort(potions.begin(), potions.end());

        for (int i = 0; i < n; i++)
        {
            long long num = spells[i];

            int l = 0, r = m - 1;
            int answer = m;
            while (l <= r)
            {
                int mid = (l + (r - l) / 2);
                if ((num * potions[mid]) >= success)
                {
                    answer = mid;
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }

            ans[i] = m - answer;
        }

        return ans;
    }
};
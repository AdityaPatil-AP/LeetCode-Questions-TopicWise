class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int maxi = 0;
        for (int i = 0; i < points.size(); i++)
        {
            unordered_map<double, int> mp;
            for (int j = 0; j < points.size(); j++)
            {
                if (i == j)
                    continue;
                else
                {
                    double m = ((double)points[i][0] - points[j][0]) / ((double)(points[i][1] - points[j][1]));
                    mp[m]++;
                }
            }
            for (auto m : mp)
            {
                maxi = max(maxi, m.second);
            }
            mp.clear();
        }
        return maxi + 1;

        // Without using division operator and finding dx and dy for slopes.

        int maxi = 0;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < points.size(); i++)
        {

            for (int j = 0; j < points.size(); j++)
            {
                if (i == j)
                    continue;
                else
                {
                    int dx = points[i][0] - points[j][0];
                    int dy = points[i][1] - points[j][1];
                    int d = gcd(dx, dy);
                    pair<int, int> p = make_pair(dx / d, dy / d);
                    mp[p]++;
                }
            }
            for (auto m : mp)
            {
                maxi = max(maxi, m.second);
            }
            mp.clear();
        }
        return maxi + 1;
    }
};
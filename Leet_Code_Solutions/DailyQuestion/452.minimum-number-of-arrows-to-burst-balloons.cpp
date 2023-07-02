class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (points.size() == 0)
            return 0;
        sort(points.begin(), points.end(), [](auto &p1, auto &p2)
             { return p1[1] < p2[1]; });
        int end = points[0][1];
        int n = points.size();
        int res = 1; // for the last group as well we will require one arrow.
        for (auto point : points)
        {
            if (point[0] <= end)
            {
                continue;
            }
            res++;
            end = point[1];
        }
        return res;
    }
};
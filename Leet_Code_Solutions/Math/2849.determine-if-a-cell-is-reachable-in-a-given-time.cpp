
class Solution
{
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t)
    {
        int height = abs(sx - fx);
        int weight = abs(sy - fy);

        if (height == 0 && weight == 0 && t == 1)
        {
            return false;
        }

        return t >= max(height, weight);
    }
};
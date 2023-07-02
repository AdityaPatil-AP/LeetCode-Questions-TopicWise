class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        // check if parallel to x-axis or y-axis.

        long long numerator = (coordinates[0][1] - coordinates[1][1]);
        long long denominator = (coordinates[0][0] - coordinates[1][0]);

        for (int i = 2; i < coordinates.size(); i++)
        {
            long long currNumerator = (coordinates[0][1] - coordinates[i][1]);
            long long currDenominator = (coordinates[0][0] - coordinates[i][0]);

            if ((numerator * currDenominator) != (denominator * currNumerator))
            {
                return false;
            }
        }

        return true;
    }
};
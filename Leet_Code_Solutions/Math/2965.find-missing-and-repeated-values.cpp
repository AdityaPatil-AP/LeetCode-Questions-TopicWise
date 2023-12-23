class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        int n = grid.size();

        int total = ((n * n) * (n * n + 1)) / 2;

        int sum = 0;
        int repeating_number;
        set<int> st;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                sum += grid[i][j];
                if (st.find(grid[i][j]) != st.end())
                {
                    repeating_number = grid[i][j];
                }
                st.insert(grid[i][j]);
            }
        }

        int change = sum - total;
        int missing_number = repeating_number - change;

        return {repeating_number, missing_number};
    }
};
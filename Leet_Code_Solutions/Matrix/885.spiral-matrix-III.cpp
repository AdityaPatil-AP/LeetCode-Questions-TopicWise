class Solution
{
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
    {
        // for all directions.
        // 1) east -> south -> west -> north.

        vector<int> dr = {0, 1, 0, -1};
        vector<int> dc = {1, 0, -1, 0};

        vector<vector<int>> ans;

        int t = 0;

        ans.push_back({rStart, cStart});
        t++;
        if (rows * cols == t)
            return ans;

        for (int k = 1; k < 2 * max(rows, cols); k += 2)
        {
            for (int i = 0; i < 4; i++)
            {                         // i -> direction index.
                int dk = k + (i / 2); // Number of steps in this direction.
                for (int j = 0; j < dk; j++)
                {
                    // step in the ith direction.
                    rStart += dr[i];
                    cStart += dc[i];

                    if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols)
                    {
                        ans.push_back({rStart, cStart});
                        t++;
                        if (t == rows * cols)
                            return ans;
                    }
                }
            }
        }

        throw NULL;
    }
};
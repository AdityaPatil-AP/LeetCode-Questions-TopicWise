class Solution
{
public:
    int numSpecial(vector<vector<int>> &mat)
    {
        map<int, int> row;
        map<int, int> col;
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0; i < n; i++)
        {
            int ones = 0;
            ;
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 1)
                    ones++;
            }

            row[i] = ones;
        }

        for (int i = 0; i < m; i++)
        {
            int ones = 0;
            for (int j = 0; j < n; j++)
            {
                if (mat[j][i] == 1)
                    ones++;
            }

            col[i] = ones;
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (row[i] == 1 && col[j] == 1 && mat[i][j] == 1)
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};
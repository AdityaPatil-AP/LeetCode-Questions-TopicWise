class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        int rowstart = 0;
        int colstart = 0;

        int rowend = n - 1;
        int colend = m - 1;

        vector<int> ans;

        while (rowstart <= rowend && colstart <= colend)
        {
            // right.
            for (int i = colstart; i <= colend; i++)
            {
                ans.push_back(matrix[rowstart][i]);
            }
            rowstart++;

            // down.
            for (int i = rowstart; i <= rowend; i++)
            {
                ans.push_back(matrix[i][colend]);
            }
            colend--;

            // left.
            if (rowend < rowstart)
                break;
            for (int i = colend; i >= colstart; i--)
            {
                ans.push_back(matrix[rowend][i]);
            }
            rowend--;

            //  up.
            if (colend < colstart)
                break;
            for (int i = rowend; i >= rowstart; i--)
            {
                ans.push_back(matrix[i][colstart]);
            }
            colstart++;
        }

        return ans;
    }
};
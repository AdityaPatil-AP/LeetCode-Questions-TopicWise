class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        // int matrix[n][n];

        int number = 1;

        int rowstart = 0;
        int colstart = 0;

        int rowend = n - 1;
        int colend = n - 1;

        while (rowstart <= rowend && colstart <= colend)
        {
            // right.
            for (int i = colstart; i <= colend; i++)
            {
                matrix[rowstart][i] = number++;
            }
            rowstart++;

            // down;
            for (int i = rowstart; i <= rowend; i++)
            {
                matrix[i][colend] = number++;
            }
            colend--;

            if (rowend < rowstart)
                break;

            // left.
            for (int i = colend; i >= colstart; i--)
            {
                matrix[rowend][i] = number++;
            }
            rowend--;

            if (colend < colstart)
                break;
            //  up
            for (int i = rowend; i >= rowstart; i--)
            {
                matrix[i][colstart] = number++;
            }
            colstart++;
        }

        return matrix;
    }
};
class Solution
{
public:
    // Recursive way...
    // vector<vector<int>> ans;
    // vector<vector<int>> generate(int n) {
    //     if(n){
    //         generate(n - 1);
    //         ans.push_back(vector<int>(n, 1));
    //         for(int i = 1;i < n - 1;i++){
    //             ans[n - 1][i] = ans[n - 2][i - 1] + ans[n - 2][i];
    //         }
    //     }
    //     return ans;
    // }

    // Building from the base - Iterative way.
    vector<vector<int>> generate(int n)
    {
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            ans.push_back(vector<int>(i + 1, 1));
            for (int j = 1; j < i; j++)
            {
                ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];
            }
        }
        return ans;
    }
};

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> triangle;
        if (numRows == 0)
            return triangle;

        triangle.push_back({1});

        for (int i = 1; i < numRows; ++i)
        {
            vector<int> prev_row = triangle.back();
            vector<int> new_row = {1};

            for (int j = 1; j < prev_row.size(); ++j)
            {
                new_row.push_back(prev_row[j - 1] + prev_row[j]);
            }

            new_row.push_back(1);
            triangle.push_back(new_row);
        }

        return triangle;
    }
};
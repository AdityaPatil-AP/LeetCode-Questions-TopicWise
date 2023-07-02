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
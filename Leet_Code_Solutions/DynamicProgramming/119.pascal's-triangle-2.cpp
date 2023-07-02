class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        // // Direct Bottom Up approach.
        // // vector<vector<int>> ans;
        // // Space - Optimised as well.
        // vector<int> prev(1, 1);
        // vector<int> curr;
        // for(int i = 1;i <= rowIndex;i++){
        //     // ans.push_back(vector<int>(i + 1, 1));
        //     curr.assign(i + 1, 1);
        //     for(int j = 1;j < i;j++){
        //         curr[j] = prev[j] + prev[j - 1];
        //     }
        //     prev = curr;
        // }
        // return prev;

        // Recursive way.
        if (rowIndex == 0)
            return {1};

        vector<int> currRow = {1};
        vector<int> prevRow = getRow(rowIndex - 1);

        for (int i = 1; i < rowIndex; i++)
        {
            currRow.push_back(prevRow[i] + prevRow[i - 1]);
        }

        currRow.push_back(1);
        return currRow;
    }
};
class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int n = strs.size();    // number of rows.
        int m = strs[0].size(); // number of columns.
        int count = 0;          // number of columns to be deleted.
        // For every column go and check if it is present in lexicographic order(alphabetical order).
        for (int i = 0; i < m; i++)
        {
            bool orderPresent = true;
            for (int j = 0; j < n - 1; j++)
            {
                if (strs[j][i] > strs[j + 1][i])
                {
                    orderPresent = false;
                    break;
                }
            }
            if (!orderPresent)
                count++;
        }
        return count;
    }
};
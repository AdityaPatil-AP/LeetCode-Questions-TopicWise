class Solution
{
public:
    bool solve(vector<vector<char>> &board)
    {
        vector<set<int>> rows(9), cols(9), sub(9);
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    continue;
                }
                int curr = board[i][j];
                if (rows[i].count(curr) || cols[j].count(curr) || sub[3 * (i / 3) + (j / 3)].count(curr))
                {
                    return false;
                }
                rows[i].insert(curr);
                cols[j].insert(curr);
                sub[3 * (i / 3) + (j / 3)].insert(curr);
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>> &board)
    {
        return solve(board);
    }
};
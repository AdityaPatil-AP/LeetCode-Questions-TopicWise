/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
    {
        vector<vector<int>> ans(m, vector<int>(n, -1));

        vector<int> dr = {0, 1, 0, -1};
        vector<int> dc = {1, 0, -1, 0};

        int row = 0;
        int col = 0;
        int d = 0;

        while (head)
        {
            ans[row][col] = head->val;
            head = head->next;
            // If the next cell in this direction is non minus one, then change
            // the direction otherwise not.
            int r = (row + dr[d]) % m;
            int c = (col + dc[d] + n) % n;

            // If the next value is non minus 1, then change the direction.
            if (ans[r][c] != -1)
                d = (d + 1) % 4;

            row += dr[d];
            col += dc[d];
        }

        return ans;
    }
};
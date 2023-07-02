/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void solve(TreeNode *root, int sum, int &ans)
    {
        if (root == NULL)
            return;

        sum += root->val;

        if (root->left == NULL && root->right == NULL)
        {
            ans += sum;
            return;
        }

        solve(root->left, sum * 10, ans);
        solve(root->right, sum * 10, ans);
        return;
    }

    int sumNumbers(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int ans = 0;
        solve(root, 0, ans);
        return ans;
    }
};
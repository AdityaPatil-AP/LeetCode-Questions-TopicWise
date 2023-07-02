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
    void dfs(TreeNode *root, int &count, int maxVal)
    {
        if (root == NULL)
            return;
        if (root->val >= maxVal)
        {
            count++;
            maxVal = root->val;
        }

        dfs(root->left, count, maxVal);
        dfs(root->right, count, maxVal);

        return;
    }

    int goodNodes(TreeNode *root)
    {
        int count = 0;
        int maxVal = INT_MIN;
        dfs(root, count, maxVal);

        return count;
    }
};
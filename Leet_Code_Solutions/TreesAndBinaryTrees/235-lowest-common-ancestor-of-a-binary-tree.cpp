/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        // If the current node is equal to either p or q, then it is one of the descendents.
        if (p->val == root->val || q->val == root->val)
        {
            return root;
        }

        TreeNode *l = lowestCommonAncestor(root->left, p, q);
        TreeNode *r = lowestCommonAncestor(root->right, p, q);

        if (l && r)
        {
            return root;
        }
        return l ? l : r ? r
                         : nullptr;
    }
};
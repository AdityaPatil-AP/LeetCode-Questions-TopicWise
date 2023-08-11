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
        // We have to use Post-Order Traversal for this job. First we will find
        // that for the current node if the descendents of it which are left and right
        // node subtrees contain both the nodes p and q. Then they are the answer.

        if (root == nullptr)
        {
            return nullptr;
        }

        int value = root->val;
        if (value < p->val && q->val > value)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        else if (value > p->val && value > q->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        else
        {
            return root;
        }
    }
};
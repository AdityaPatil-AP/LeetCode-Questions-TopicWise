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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        // Goal : To find they are structurally identical.
        if (!p && !q)
            return true;

        if (p && q && p->val == q->val)
        {
            bool leftAns = isSameTree(p->left, q->left);
            bool rightAns = isSameTree(p->right, q->right);
            if (leftAns && rightAns)
                return true;
            return false;
        }
        return false;
    }
};

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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q == NULL)
        {
            return true;
        }
        if (p != NULL && q != NULL)
        {
            if (isSameTree(p->left, q->left) && isSameTree(p->right, q->right))
            {
                if (p->val == q->val)
                    return true;
                else
                    return false;
            }
            else
                return false;
        }
        return false;
    }
};
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
    int sum = 0;

    int rangeSumBST(TreeNode *root, int low, int high)
    {
        // int sum = inorder(root, low, high);
        // return sum;

        // Using Stack
        stack<TreeNode *> st;
        st.push(root);

        int rangeSum = 0;
        while (!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();

            if (node->val >= low && node->val <= high)
            {
                rangeSum += node->val;
            }

            if (node->val > low)
            {
                if (node->left)
                {
                    st.push(node->left);
                }
            }

            if (node->val < high)
            {
                if (node->right)
                {
                    st.push(node->right);
                }
            }
        }

        return rangeSum;
    }

    int inorder(TreeNode *root, int low, int high)
    {
        if (root == NULL)
        {
            return 0;
        }
        int sum = 0;
        if (root->left)
        {
            if (root->left->val < low)
            {
                sum += inorder(root->left->right, low, high);
            }
            else
            {
                sum += inorder(root->left, low, high);
            }
        }

        if (root->val >= low && root->val <= high)
        {
            sum += root->val;
        }

        if (root->right)
        {
            if (root->right->val > high)
            {
                sum += inorder(root->right->left, low, high);
            }
            else
            {
                sum += inorder(root->right, low, high);
            }
        }
        return sum;
    }
};
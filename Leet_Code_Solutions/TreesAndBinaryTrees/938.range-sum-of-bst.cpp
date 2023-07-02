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
    // Recursive DFS Approach
    // int rangeSumBST(TreeNode* root, int low, int high) {
    //     if(!root) return 0;
    //     int leftSum = 0, rightSum = 0;
    //     if(root->val >= low && root->val <= high){
    //         leftSum = rangeSumBST(root->left, low, root->val - 1);
    //         rightSum = rangeSumBST(root->right, root->val + 1, high);
    //     }
    //     else if(root->val > high){
    //         return rangeSumBST(root->left, low, high);
    //     }
    //     else if(root->val < low){
    //         return rangeSumBST(root->right, low, high);
    //     }
    //     return root->val + leftSum + rightSum;
    // }

    // Iterative Approach Using Stack
    int rangeSumBST(TreeNode *root, int l, int r)
    {
        int rangeSum(0);
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();
            if (node->val >= l && node->val <= r)
                rangeSum += node->val;
            if (node->val > l)
            {
                if (node->left)
                    st.push(node->left);
            }
            if (node->val < r)
            {
                if (node->right)
                    st.push(node->right);
            }
        }
        return rangeSum;
    }
};
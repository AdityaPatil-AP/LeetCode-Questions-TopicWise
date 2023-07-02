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
    void inorder(TreeNode *root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        // arr.push_back(root->val);
        // find the difference with the previous value it is there.
        if (prevVal != NULL)
        {
            minDistance = min(minDistance, root->val - prevVal->val);
        }
        prevVal = root;

        inorder(root->right);
        return;
    }

    // With and without using an array.
    int minDiffInBST(TreeNode *root)
    {
        // vector<int> arr;
        // inorder(arr, root);
        // int diff = INT_MAX;
        // for(int i = 1;i < arr.size();i++){
        //     diff = min(diff, arr[i] - arr[i - 1]);
        // }
        // return diff;

        // Doing without array.
        inorder(root);
        return minDistance;
    }

private:
    int minDistance = INT_MAX;
    TreeNode *prevVal = NULL;
};
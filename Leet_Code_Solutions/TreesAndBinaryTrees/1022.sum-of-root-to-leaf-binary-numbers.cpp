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
class Solution {
public:
    // Using dfs
    void helper(TreeNode* root, int num, int &sum){
        if(!root) return;
        num = (num << 1) + root->val;
        if(!root->left && !root->right){
            sum += num;
        }
        helper(root->left, num, sum);
        helper(root->right, num, sum);
        return;
    }
    
    int sumRootToLeaf(TreeNode* root) {
        int num = 0;
        int sum = 0;
        helper(root, num, sum);
        return sum;
    }
};
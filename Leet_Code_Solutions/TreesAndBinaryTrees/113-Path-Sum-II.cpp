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
    
    void possibilities(TreeNode*root, int targetSum, vector<int> &ans, vector<vector<int>> &res){
        if(root == NULL) {
            return;
        }
        if(!root->left && !root->right && root->val == targetSum) {
            ans.push_back(root->val), res.push_back(ans), ans.pop_back(); 
            return;
        }
        ans.push_back(root->val);
        possibilities(root->left, targetSum - root->val, ans, res);
        possibilities(root->right, targetSum - root->val, ans, res);
        ans.pop_back();
        return;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        if(!root) return res;
        vector<int> ans;
        possibilities(root, targetSum, ans, res);
        return res;
    }
};
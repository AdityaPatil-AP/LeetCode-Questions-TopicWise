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
    int ans = 0;
    int longestZigZag(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        longestPath(root, true, 0);
        longestPath(root, false, 0);
        
        return ans;
    }
    
    // 0 -> left, 1 -> right.
    
    void longestPath(TreeNode* root, bool goLeft, int steps){
        if(root == NULL){
            return;
        }
        ans = max(ans, steps);
        if(goLeft){
            longestPath(root->left, false, steps + 1);
            longestPath(root->right, true, 1);
        }
        else{
            longestPath(root->left, false, 1);
            longestPath(root->right, true, steps + 1);
        }
    }
};
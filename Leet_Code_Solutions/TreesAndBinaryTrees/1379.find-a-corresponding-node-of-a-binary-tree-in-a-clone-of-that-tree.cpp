/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(!cloned) return NULL;
        if(cloned->val == target->val){
            return cloned;
        }
        TreeNode* ans1 = getTargetCopy(original, cloned->left, target);
        TreeNode* ans2 = getTargetCopy(original, cloned->right, target);
        if(ans1)
            return ans1;
        else 
            return ans2;
    }
};
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
    TreeNode* constructMBT(vector<int>&nums, int start, int end){
        if(start > end) return NULL;
        int maxindex = -1;
        int maxi = INT_MIN;
        for(int i = start;i <= end;i++){
            if(maxi < nums[i]){
                maxindex = i;
                maxi = nums[i];
            }
        }
        TreeNode* root = new TreeNode(maxi);
        root->left = constructMBT(nums, start, maxindex - 1);
        root->right = constructMBT(nums, maxindex + 1, end);
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMBT(nums, 0, nums.size()-1);
    }
};
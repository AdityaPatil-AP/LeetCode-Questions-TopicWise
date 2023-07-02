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
// As we have to create a height Balanced 
// Tree. First thing was sure that the differe.
// Of the left subtrees and right subtrees must
// not be greater than 1. Therefore how to 
// achieve this. For that it was obvious we 
// have to choose root for every subtree in 
// such a way that it is always in the middle
// of the array(partition). So we always 
// choose the middle element and then 
// recursively passed the left part to the left
// subtree and the right part to right subtree. These parts always differed by only one element at maximum.


class Solution {
public:
    // Solution Using Recursion.
    TreeNode* binarySearchTree(vector<int> &nums, int low, int high){
        if(low > high) return NULL;
        int mid = (low + high)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = binarySearchTree(nums, low, mid - 1);
        root->right = binarySearchTree(nums, mid + 1, high);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return binarySearchTree(nums, 0, nums.size() - 1);
    }
};
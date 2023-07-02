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
    
    // Inorder Traversal and storing values
    // void inorder(TreeNode* root, vector<int> &nums){
    //     if(!root) return;
    //     inorder(root->left, nums);
    //     nums.push_back(root->val);
    //     inorder(root->right, nums);
    //     return;
    // }
    // // Time Complexity : O(n) as we are visiting every node.
    // // Space Complexity : O(n) + O(h), Recursion Stack Space and space taken by nums array.
    // TreeNode* increasingBST(TreeNode* root) {
    //     if(!root) return NULL;
    //     vector<int> nums;
    //     inorder(root, nums);
    //     TreeNode* newroot = new TreeNode(0), *curr = newroot;
    //     for(auto i : nums){
    //         curr->right = new TreeNode(i);
    //         curr = curr->right;
    //     }
    //     return newroot->right;
    // }

    // In - order traversal with relinking.
//     TreeNode* increasingBST(TreeNode* root){
//         if(!root) return NULL;
//         TreeNode* ans = new TreeNode(0);
//         curr = ans;
//         inorder(root);
//         return ans->right;
//     }
    
//     void inorder(TreeNode* root){
//         if(!root) return;
//         inorder(root->left);
//         curr->right = new TreeNode(root->val);
//         curr = curr->right;
//         inorder(root->right);
//         return;
//     }
    
//     // private: 
//     TreeNode* curr;
    
    // Relinking without taking extra space
    TreeNode* increasingBST(TreeNode* root){
        if(!root) return NULL;
        TreeNode* ans = new TreeNode(0);
        curr = ans;
        inorder(root);
        return ans->right;
    }
    
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        root->left = NULL;
        curr->right = root;
        curr = curr->right;
        inorder(root->right);
        return;
    }
    
    // private: 
    TreeNode* curr;
};
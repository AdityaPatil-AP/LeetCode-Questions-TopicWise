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
    // Brute Force
//     int height(TreeNode* p){
//         if(p == NULL) return 0;
//         return 1 + max(height(p->left), height(p->right));
//     }
    
//     bool isBalanced(TreeNode* root) {
//         if(root == NULL || (root->right == NULL && root->left == NULL)) return true;
//         if(abs(height(root->left) - height(root->right)) <= 1){
//             return isBalanced(root->left) && isBalanced(root->right);
//         } 
//         else{
//             return false;
//         }
//     }
    
    // Optimised Appraoch
    // bool isBalanced(TreeNode* root){
    //     if(root == NULL) return true;
    //     if(root->left == NULL && root->right == NULL) return true;
    //     if(root->right == NULL){
    //         if(root->left->left == NULL && root->left->right == NULL) return true;
    //         else return false;
    //     }
    //     if(root->left == NULL){
    //         if(root->right->left == NULL && root->right->right == NULL) return true;
    //         else return false;
    //     }
    //     bool leftSubtree = isBalanced(root->left);
    //     bool rightSubtree = isBalanced(root->right);
    //     return (leftSubtree && rightSubtree); 
    // }
    
    // Optimised approach : O(n) time complexity : O(log2n) space complexity
    
//     bool ans;
    
//     int Check(TreeNode *root){
//         if(!root) return 0;
//         if(!ans) return 0;
//         int leftpart = Check(root->left);
//         int rightpart = Check(root->right);
        
//         if(abs(leftpart - rightpart) > 1) ans = false;
//         return 1 + max(leftpart, rightpart);
//     }
    
//     bool isBalanced(TreeNode *root){
//         ans = true;
//         int check = Check(root);
//         return ans;
//     }
    
    // Another approach
    bool isBalanced(TreeNode* root){
        if(root == NULL) return true;
        if(Height(root) == -1) return false;
        return true;
    }
    int Height(TreeNode* root){
        if(root== NULL) return 0;
        int leftpart = Height(root->left);
        int rightpart = Height(root->right);
        if(leftpart == -1 || rightpart == -1 || abs(leftpart - rightpart) > 1) return -1;
        return 1 + max(leftpart, rightpart);
    }
};
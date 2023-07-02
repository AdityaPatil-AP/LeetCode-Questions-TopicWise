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
    // Using DFS
//     void helper(TreeNode* root, int &sum){
//         if(!root) return;
//         if(root->val % 2== 0){
//             if(root->left && root->left->left){
//                 sum += root->left->left->val;
//             }
//             if(root->left && root->left->right){
//                 sum += root->left->right->val;
//             }
//             if(root->right && root->right->left){
//                 sum += root->right->left->val;
//             }
//             if(root->right && root->right->right){
//                 sum += root->right->right->val;
//             }
//         }
//         helper(root->left, sum);
//         helper(root->right, sum);
//         return;
//     }
    
//     int sumEvenGrandparent(TreeNode* root) {
//         int sum = 0;
//         helper(root, sum);
//         return sum;
//     }
    
    // Using BFS
    int sumEvenGrandparent(TreeNode* root){
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int sum = 0;
        while(!q.empty()){
            int n = q.size();
            for(int i = 0;i < n;i++){
                TreeNode* current = q.front();
                q.pop();
                if(current->val % 2 == 0){
                    if(current->left && current->left->left){
                        sum += current->left->left->val;
                    }
                    if(current->left && current->left->right){
                        sum += current->left->right->val;
                    }
                    if(current->right && current->right->left){
                        sum += current->right->left->val;
                    }
                    if(current->right && current->right->right){
                        sum += current->right->right->val;
                    }
                }
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
            }
        }
        return sum;
    }
};
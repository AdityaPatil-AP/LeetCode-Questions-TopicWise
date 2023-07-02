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
//     // Using Height and DFS
//     int height(TreeNode* root){
//         if(!root) return 0;
//         return 1 + max(height(root->left), height(root->right));
//     }
    
//     void helper(TreeNode* root, int height, int &sum){
//         if(!root) return;
//         if(height == 1){
//             sum += root->val;
//         }
//         helper(root->left, height - 1, sum);
//         helper(root->right, height - 1, sum);
//         return;
//     }
    
//     int deepestLeavesSum(TreeNode* root) {
//         int h = height(root);
//         int sum = 0;
//         helper(root, h, sum);
//         return sum;
//     }
    
    // Using bfs
    // int deepestLeavesSum(TreeNode* root){
    //     int sum = 0, n;
    //     queue<TreeNode*> q;
    //     q.push(root);
    //     while(!q.empty()){
    //         n = q.size(), sum = 0;
    //         for(int i = 0;i < n;i++){
    //             TreeNode* current = q.front();
    //             q.pop();
    //             sum += current->val;
    //             if(current->left) q.push(current->left);
    //             if(current->right) q.push(current->right);
    //         }
    //     }
    //     return sum;
    // }
    
    // Using Dfs
    void helper(TreeNode *root, int &sum, int depth, int &deepest){
        if(!root) return;
        if(!root->left && !root->right){
            if(depth == deepest){
                sum += root->val;
            }
            else if(depth > deepest){
                deepest = depth;
                sum = root->val;
            }
            // else if depth < deepest then don't consider that element for summation
        }
        helper(root->left, sum, depth + 1, deepest);
        helper(root->right, sum, depth + 1, deepest);
        return;
    }
    
    int deepestLeavesSum(TreeNode* root){
        int deepest = 1;
        int depth = 1;
        int sum = 0;
        helper(root, sum, depth, deepest);
        return sum;
    }
};
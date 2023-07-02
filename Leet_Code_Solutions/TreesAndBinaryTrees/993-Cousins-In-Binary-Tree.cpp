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
    // 1) BFS and queue approach
    // bool isCousins(TreeNode* root, int x, int y) {
    //     if(!root) return false;
    //     queue<TreeNode*> q;
    //     q.push(root);
    //     while(!q.empty()){
    //         bool f1 = false, f2 = false;
    //         int n = q.size();
    //         for(int i = 0;i < n;i++){
    //             auto current =  q.front();
    //             q.pop();
    //             // checking if parent is same..
    //             if(current->val == x) f1 = true;
    //             if(current->val == y) f2 = true;
    //             if(current->left && current->right){
    //                 if((current->left->val == x && current->right->val == y) || (current->left->val == y && current->right-> val == x)){
    //                     return false;
    //                 }
    //             }
    //             if(current->left) q.push(current->left);
    //             if(current->right) q.push(current->right);
    //         }
    //         if(f1 && f2){
    //             return true;
    //         }
    //         else if(f1 || f2){
    //             return false;
    //         }
    //     }
    //     return false;
    // }
    
    // Using DFS - Works Damn Faster.
    void helper(TreeNode* root, int level, int par_val, int x, int y){
        if(root == NULL) return;
        if(root->val == x){
            xdepth = level;
            xparent = par_val;
            return;
        }
        if(root->val == y){
            ydepth = level;
            yparent = par_val;
            return;
        }
        helper(root->left, level + 1, root->val, x, y);
        helper(root->right, level + 1, root->val, x, y);
    }
    
    bool isCousins(TreeNode* root, int x, int y){
        if(!root) return false;
        if(root->val == x || root->val == y){
            return false;
        }
        // parameters root, level, parent_val, x, y
        helper(root, 0, 0, x, y);
        if(xdepth == ydepth && xparent != yparent){
            return true;
        }
        return false;
    }
    
    private:
    int xparent, yparent, xdepth, ydepth;
};
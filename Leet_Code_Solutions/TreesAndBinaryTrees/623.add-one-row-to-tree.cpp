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
    // Using DFS - Correct Way.
//     void helper(TreeNode* root, int val, int depth){
//         if(!root) return;
//         // If we reach the depth - 1, we have to add the row, So we create two new nodes and attach on 
//         // the left and right part of the tree, and after that we attach our original subtree on left and right part
//         // of those subtrees respectively.
//         if((depth - 1) == 1){
//             TreeNode* temp1, *temp2;
//             temp1 = root->left;
//             temp2 = root->right;
//             root->left = new TreeNode(val);
//             root->right = new TreeNode(val);
//             root->left->left = temp1;
//             root->right->right = temp2;
//             return;
//         }
//         // Go for the (depth - 1) in the left subtree and make the necessary changes.
//         helper(root->left, val, depth - 1);
//         // Go for the (depth - 1) in the right subtree and make the changes.
//         helper(root->right, val, depth - 1);
//         return;
//     }
    
//     TreeNode* addOneRow(TreeNode* root, int val, int depth) {
//         if(!root) return NULL;
//         // If the given depth is 1.
//         // Add the new node as the root and attach the whole tree as it's left subtree.
//         if(depth == 1){
//             TreeNode* newRoot = new TreeNode(val);
//             newRoot->left = root;
//             return newRoot;
//         }
//         helper(root, val, depth);
//         return root;
//     }
    
    // 2) Using BFS
    TreeNode* addOneRow(TreeNode* root, int val, int depth){
        if(!root) return NULL;
        // If depth == 1, then we create newRoot and add the tree as it's left Subtree and return.
        if(depth == 1){
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        // While we don't reach the depth - 1 level we keep updating our queue, 
        // As our queue at any instant contains the nodes at a particular level.
        queue<TreeNode*> q;
        q.push(root);
        int d = 1;
        // To get the nodes at the depth - 1, current level. 
        while(d < depth - 1){
            int n = q.size();
            for(int i = 0;i < n;i++){
                TreeNode* current = q.front();
                q.pop();
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
            }
            depth++;
        }
        while(!q.empty()){
            TreeNode *current = q.front();
            q.pop();
            TreeNode* temp = current->left;
            current->left = new TreeNode(val);
            current->left->left = temp;
            temp = current->right;
            current->right = new TreeNode(val);
            current->right->right = temp;
        }
        return root;
    }
};
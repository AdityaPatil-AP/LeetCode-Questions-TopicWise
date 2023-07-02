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
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> arr;
        if(root == NULL) return arr;
        queue<TreeNode*> q;
        q.push(root);
        // q.push(NULL);
        vector<int> level;
        while(!q.empty()){
            // if(current == NULL){
            //     arr.push_back(level);
            //     level.clear();
            //     q.pop();
            //     if(q.empty()){
            //         break;
            //     }
            //     q.push(NULL);
            //     continue;
            // }
            int n = q.size();
            for(int i = 0;i < n;i++){
                TreeNode* current = q.front();
                level.push_back(current->val);
                if(current->left != NULL) q.push(current->left);
                if(current->right != NULL) q.push(current->right);
                q.pop();
            }
            arr.push_back(level);
            level.clear();
        }
        return arr;
    }
};
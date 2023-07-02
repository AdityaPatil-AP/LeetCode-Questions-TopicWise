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
    // Recursive DFS Approach
    // TreeNode* searchBST(TreeNode* root, int val) {
    //     if(!root) return NULL;
    //     if(root->val < val){
    //         return searchBST(root->right, val);
    //     }
    //     else if(root->val > val){
    //         return searchBST(root->left, val);
    //     }
    //     else{
    //         return root;
    //     }
    // }
    
    // Iterative Approach
    TreeNode* searchBST(TreeNode* root, int val){
        if(!root) return NULL;
        stack<TreeNode*> st;
        TreeNode* ans = NULL;
        st.push(root);
        while(!st.empty()){
            TreeNode* curr = st.top();
            st.pop();
            if(curr->val == val){
                ans = curr;
                break;
            }
            else if(curr->val > val){
                if(curr->left) st.push(curr->left);
                else break;
            }
            else{
                if(curr->right) st.push(curr->right);
                else break;
            }
        }
        return ans;
    }
};
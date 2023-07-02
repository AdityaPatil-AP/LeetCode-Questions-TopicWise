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
    TreeNode* createTree(vector<int>& preorder, int start, int end){
        if(start > end) return NULL;
        TreeNode* root = new TreeNode(preorder[start]);
        int index;
        for(int i = start + 1;i <= end;i++){
            if(preorder[i] > preorder[start]){
                index = i;
                break;
            }
        }
        root->left = createTree(preorder, start + 1, index - 1);
        root->right = createTree(preorder, index, end);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int start = 0;
        int end = preorder.size() - 1;
        return createTree(preorder, start, end);
    }
};
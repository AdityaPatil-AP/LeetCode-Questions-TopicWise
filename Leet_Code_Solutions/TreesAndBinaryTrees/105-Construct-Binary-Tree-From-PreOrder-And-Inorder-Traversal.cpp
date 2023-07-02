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
    // To know the current position of the root for that tree
    int preInd = 0;
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // To find the index of the root in O(1) time we can pass the map in the function call
        map<int, int> mp;
        for(int i = 0;i < inorder.size();i++){
             mp[inorder[i]] = i;
        }
        return buildTree(preorder, inorder, 0, inorder.size() - 1, mp);
    }
    
    TreeNode* buildTree(vector<int> &preorder, vector<int>& inorder, int start, int end, map<int, int> &mp){
        // To denote that we don't have any node and return NULL.
        if(start > end){
            return NULL;
        }
        // Making the root node for the tree
        TreeNode* root = new TreeNode(preorder[preInd++]);
        // Using map we find the position of the root node in the inorder array in O(1) time.
        int pos = mp[root->val];
        
        // Making recursion calls to partition the tree into left and right subtree and build them.
        root->left = buildTree(preorder, inorder, start, pos - 1, mp);
        root->right = buildTree(preorder, inorder, pos + 1, end, mp);
        // At last we return the root as the answer.
        return root;
    }
};
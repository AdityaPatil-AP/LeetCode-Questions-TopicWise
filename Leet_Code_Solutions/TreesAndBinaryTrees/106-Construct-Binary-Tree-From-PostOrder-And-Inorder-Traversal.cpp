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
    // I will get parents from postorder traversal.
    // I will find the location of the parent in inorder traversal and break it into further right and left subtrees.

    TreeNode *buildTree(vector<int> inorder, vector<int> postorder)
    {
        int n = inorder.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[inorder[i]] = i;
        }
        int index = n - 1;
        return solve(inorder, postorder, 0, n - 1, index, mp);
    }

    TreeNode *solve(vector<int> &inorder, vector<int> &postorder, int start, int end, int &index, unordered_map<int, int> &mp)
    {
        // No nodes available
        if(start > end) return NULL;

        // Current parent.
        int parent = postorder[index];
        // Updating the index for the next subtree.
        index--;

        // Finding the position of the parent in the inorder tree.
        // Because it will help us to separate the left subtree from the right subtree.
        int idx = mp[parent];

        TreeNode *root = new TreeNode(inorder[idx]);

        // Here we are building the right tree first because in post order traversal.
        // if we see at the last we have the root node, before that we have the root node of the right subtree.
        // Therefore we have to first build the right subtree and then the left subtree.
        root->right = solve(inorder, postorder, idx + 1, end, index, mp);
        root->left = solve(inorder, postorder, start, idx - 1, index, mp);

        return root;
    }
};
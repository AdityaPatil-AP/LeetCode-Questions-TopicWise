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
class Solution
{
public:
    //     void dfs(TreeNode* &root, vector<TreeNode*> &ans, map<int, int> &mp){
    //         if(root == NULL) return;
    //         dfs(root->left, ans, mp);
    //         dfs(root->right, ans, mp);
    //         if(mp[root->val] == 1){
    //             if(root->left){
    //                 ans.push_back(root->left);
    //             }
    //             if(root->right){
    //                 ans.push_back(root->right);
    //             }
    //             root = NULL;
    //         }

    //         return;
    //     }

    // Update Idea using the prev node (parent).
    void dfs(TreeNode *prev, TreeNode *&root, vector<TreeNode *> &ans, map<int, int> &mp)
    {
        if (root == NULL)
            return;

        if (mp[prev->val] && !mp[root->val])
            ans.push_back(root);

        dfs(root, root->left, ans, mp);
        dfs(root, root->right, ans, mp);

        if (mp[root->val])
        {
            root = NULL;
        }

        return;
    }

    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        map<int, int> mp;
        for (int i = 0; i < to_delete.size(); i++)
        {
            mp[to_delete[i]] = 1;
        }

        vector<TreeNode *> ans;
        TreeNode *prev = new TreeNode(0);
        mp[0] = 1;
        dfs(prev, root, ans, mp);
        // if(root && mp[root->val] == 0){
        //     ans.push_back(root);
        // }
        return ans;
    }
};
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
    int averageOfSubtree(TreeNode *root)
    {

        vector<int> ans = dfs(root);

        return ans[0];
    }

    vector<int> dfs(TreeNode *root)
    {
        // {count of nodes equal to average, sum, count};
        if (root == NULL)
        {
            return {0, 0, 0};
        }

        vector<int> ans1 = dfs(root->left);
        vector<int> ans2 = dfs(root->right);

        // Subtree Average.
        int sum = root->val + ans1[1] + ans2[1];
        int count = 1 + ans1[2] + ans2[2];
        int equalcount = ans1[0] + ans2[0];
        if (sum / count == root->val)
        {
            equalcount += 1;
        }

        return {equalcount, sum, count};
    }
};
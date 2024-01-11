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
    int ans = 0;
    int maxAncestorDiff(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        find(root, {root->val, root->val});

        return ans;
    }

    void find(TreeNode *root, pair<int, int> extremes)
    {
        if (root == NULL)
            return;

        int low = extremes.first;
        int high = extremes.second;

        ans = max(ans, max(abs(low - root->val), abs(high - root->val)));

        if (root->val < low)
        {
            low = root->val;
        }
        if (root->val > high)
        {
            high = root->val;
        }

        find(root->left, {low, high});
        find(root->right, {low, high});

        return;
    }
};
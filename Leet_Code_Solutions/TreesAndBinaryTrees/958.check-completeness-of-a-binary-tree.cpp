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
    bool isCompleteTree(TreeNode *root)
    {
        // BFS.

        if (root == NULL)
            return true;

        queue<TreeNode *> q;
        q.push(root);

        bool nullNodeFound = false;
        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();

            if (curr == NULL)
            {
                nullNodeFound = true;
            }
            else
            {
                if (nullNodeFound == true)
                {
                    return false;
                }

                q.push(curr->left);
                q.push(curr->right);
            }
        }

        return true;
    }
};
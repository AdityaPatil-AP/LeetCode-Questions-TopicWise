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
    bool isEvenOddTree(TreeNode *root)
    {
        if (!root)
            return false;
        queue<TreeNode *> q;
        q.push(root);
        int lev = 0;
        while (!q.empty())
        {
            int n = q.size();
            vector<int> level;
            for (int i = 0; i < n; i++)
            {
                TreeNode *current = q.front();
                q.pop();
                level.push_back(current->val);
                if (current->left)
                    q.push(current->left);
                if (current->right)
                    q.push(current->right);
            }
            if (lev % 2 == 0)
            {
                int prev = INT_MIN;
                for (int i = 0; i < level.size(); i++)
                {
                    if (level[i] % 2 == 1)
                    {
                        if (level[i] > prev)
                        {
                            prev = level[i];
                            continue;
                        }
                        else
                            return false;
                    }
                    else
                        return false;
                }
            }
            else
            {
                int prev = INT_MAX;
                for (int i = 0; i < level.size(); i++)
                {
                    if (level[i] % 2 == 0)
                    {
                        if (level[i] < prev)
                        {
                            prev = level[i];
                            continue;
                        }
                        else
                            return false;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            lev++;
            level.clear();
        }
        return true;
    }
};

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
    bool isEvenOddTree(TreeNode *root)
    {
        int level = 0;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int num1 = 0;
            int num2 = INT_MAX;
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                if (level % 2 == 0)
                {
                    TreeNode *curr = q.front();
                    if (curr->val % 2 == 0 || curr->val <= num1)
                    {
                        return false;
                    }
                    q.pop();
                    num1 = curr->val;
                    if (curr->left)
                        q.push(curr->left);
                    if (curr->right)
                        q.push(curr->right);
                }
                else
                {
                    TreeNode *curr = q.front();
                    if (curr->val % 2 == 1 || curr->val >= num2)
                    {
                        return false;
                    }
                    q.pop();
                    num2 = curr->val;
                    if (curr->left)
                        q.push(curr->left);
                    if (curr->right)
                        q.push(curr->right);
                }
            }
            level++;
        }

        return true;
    }
};
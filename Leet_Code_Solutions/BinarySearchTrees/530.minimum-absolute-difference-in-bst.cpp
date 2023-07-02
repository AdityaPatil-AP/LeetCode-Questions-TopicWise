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
    // Using Depth First Search and Recursion.
    void inorder(TreeNode *root, vector<int> &arr)
    {
        if (!root)
            return;

        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);

        return;
    }

    int getMinimumDifference(TreeNode *root)
    {
        vector<int> arr;
        inorder(root, arr);

        int minDifference = INT_MAX;
        for (int i = 1; i < arr.size(); i++)
        {
            minDifference = min(minDifference, arr[i] - arr[i - 1]);
        }

        return minDifference;
    }
};

// Using prev pointer

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
    int ans = INT_MAX;
    TreeNode *prev;

    // Using Depth First Search and Recursion.
    void inorder(TreeNode *root)
    {
        if (!root)
            return;

        inorder(root->left);

        if (prev != NULL)
        {
            ans = min(ans, abs(root->val - prev->val));
        }

        prev = root;

        inorder(root->right);

        return;
    }

    int getMinimumDifference(TreeNode *root)
    {

        inorder(root);

        return ans;
    }
};
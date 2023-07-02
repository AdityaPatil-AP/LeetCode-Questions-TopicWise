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
    // Putting the correct element at the correct index, by using the map and storing their original positions.
    // as we go we keep on updating their positions if they don't match.

    // Using Hashmap and BFS.
    int findOperations(vector<int> &arr)
    {

        vector<int> sorted_A = arr;
        sort(sorted_A.begin(), sorted_A.end());

        map<int, int> position;

        for (int i = 0; i < arr.size(); i++)
        {
            position[arr[i]] = i;
        }

        int steps = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (sorted_A[i] == arr[i])
            {
                continue;
            }

            int p = position[sorted_A[i]];
            position[sorted_A[i]] = i;
            position[arr[i]] = p;
            swap(arr[i], arr[p]);
            steps++;
        }

        return steps;
    }

    int minimumOperations(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        int operations = 0;
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
            operations += findOperations(level);
        }
        return operations;
    }
};
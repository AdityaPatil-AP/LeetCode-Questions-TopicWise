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
    int amountOfTime(TreeNode *root, int start)
    {
        unordered_map<int, vector<int>> graph;
        convert(root, 0, graph);

        // Do the bfs and find the farthest vertex for the starting point.
        queue<int> q;
        unordered_set<int> visited;
        visited.insert(start);
        q.push(start);
        int minute = 0;

        while (!q.empty())
        {
            int levelSize = q.size();
            while (levelSize > 0)
            {
                int current = q.front();
                q.pop();

                for (int num : graph[current])
                {
                    if (visited.find(num) == visited.end())
                    {
                        visited.insert(num);
                        q.push(num);
                    }
                }
                levelSize--;
            }
            minute++;
        }

        return (minute - 1);
    }

    void convert(TreeNode *node, int parent, unordered_map<int, vector<int>> &graph)
    {
        if (node == NULL)
            return;

        if (parent != 0)
        {
            graph[node->val].push_back(parent);
        }
        if (node->left)
            graph[node->val].push_back(node->left->val);
        if (node->right)
            graph[node->val].push_back(node->right->val);

        convert(node->left, node->val, graph);
        convert(node->right, node->val, graph);
    }
};
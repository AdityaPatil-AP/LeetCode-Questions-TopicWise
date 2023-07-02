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
    int maxLevelSum(TreeNode *root)
    {
        // if(root == NULL) return 0;
        // vector<int> levelSum;
        // queue<TreeNode*> q;
        // q.push(root);
        // while(!q.empty()){
        //     int n = q.size();
        //     int sum = 0;
        //     for(int i = 0;i < n;i++){
        //         TreeNode* current = q.front();
        //         sum += current->val;
        //         if(current->left) q.push(current->left);
        //         if(current->right) q.push(current->right);
        //         q.pop();
        //     }
        //     levelSum.push_back(sum);
        // }
        // int level = 0;
        // for(int i = 1;i < levelSum.size();i++){
        //     if(levelSum[i] > levelSum[level]){
        //         level = i;
        //     }
        // }
        // return level + 1;

        if (root == NULL)
            return 0;

        queue<TreeNode *> q;

        int ans = 1;
        int max_sum = INT_MIN;
        int level = 1;
        q.push(root);

        while (!q.empty())
        {
            int n = q.size();

            int sum = 0;
            for (int i = 0; i < n; i++)
            {
                TreeNode *curr = q.front();
                q.pop();

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
                sum += curr->val;
            }

            if (sum > max_sum)
            {
                ans = level;
                max_sum = sum;
            }

            level++;
        }

        return ans;
    }
};
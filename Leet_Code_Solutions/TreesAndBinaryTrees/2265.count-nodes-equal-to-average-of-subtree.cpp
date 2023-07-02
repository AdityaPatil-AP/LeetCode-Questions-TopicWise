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
    // Using DFS
//     void helper(TreeNode* root, int &count, int &sum, int &ans){
//         if(!root) return;
//         int count1 = 0, count2 = 0, sum1 = 0, sum2 = 0;
//         helper(root->left, count1, sum1, ans);
//         helper(root->right, count2, sum2, ans);
//         sum = root->val + sum1+ sum2;
//         count = 1 + count1 + count2;
//         int average = sum/count;
//         if(average == root->val) ans += 1;
//         return;
//     }
    
//     int averageOfSubtree(TreeNode* root) {
//         int count = 0;
//         int sum = 0;
//         int ans = 0;
//         helper(root, count, sum, ans);
//         return ans;
//     }
    
    // Using Dfs and pair<int, int>
    // pair first - indicates sum of the subtree, and second indicates the count of nodes in the subtree
    pair<int, int> count(TreeNode* root, int &ans1){
        if(!root) return {0, 0};
        auto left = count(root->left, ans1);
        auto right = count(root->right, ans1);
        pair<int, int> ans;
        ans.first = (left.first + right.first + root->val);
        ans.second = (left.second + right.second + 1);
        int average = ans.first/ans.second;
        if(average == root->val) ans1++;
        return ans;
    }
    
    int averageOfSubtree(TreeNode* root){
        int count1 = 0;
        auto ans = count(root, count1);
        return count1;
    }
};
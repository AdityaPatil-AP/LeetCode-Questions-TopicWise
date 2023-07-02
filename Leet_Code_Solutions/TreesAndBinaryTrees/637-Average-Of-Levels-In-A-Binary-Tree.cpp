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
    // vector<double> averageOfLevels(TreeNode* root) {
    //     // if root is NULL 
    //     if(!root) return {};
    //     // Declaring queue for storing the nodes of the next level..
    //     queue<TreeNode*> q;
    //     // Pushing the 0th level
    //     q.push(root);
    //     // double ans vector
    //     vector<double> ans;
    //     // setting the precision to 6
    //     cout << setprecision(6);
    //     while(!q.empty()){
    //         // Same bfs steps..
    //         int n = q.size();
    //         double temp = 0;
    //         for(int i = 0;i < n;i++){
    //             TreeNode* current = q.front();
    //             q.pop();
    //             temp += current->val;
    //             if(current->left) q.push(current->left);
    //             if(current->right) q.push(current->right);
    //         }
    //         ans.push_back(temp/n);
    //     }
    //     return ans;
    // }
    
    // 2) Using DFS 
    void helper(vector<double> &average, vector<int> &elements, int level, TreeNode* root){
        if(!root) return;
        if(level >= average.size()){
            elements.push_back(0); // Currently the element at this new created level is 0.
            average.push_back(0.0); // Currently the average of that level is also 0.0.
        }
        elements[level] += 1; // elements at that level is increased by 1;
        average[level] = (average[level] * (elements[level] - 1) + root->val)/elements[level];
        // We have to fill the right and the left Subtrees.
        
        helper(average, elements, level + 1, root->left);
        helper(average, elements, level + 1, root->right);
        return;
    }
    
    vector<double> averageOfLevels(TreeNode* root){
        vector<double> average; // this will store the average of every level;
        vector<int> elements; // this will store the number of elements at that level.
        cout << setprecision(6);
        if(!root) return average;
        helper(average, elements, 0, root);
        return average;
    }
};
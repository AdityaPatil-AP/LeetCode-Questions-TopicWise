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
    // Here I have analysed five ways of doing this question.
    // Only some functions or technique would vary. Crux is the BFS and in one 
    // approach we use BFS.
    
    // 1) Using queue and reverse function.
    // vector<vector<int>> levelOrderBottom(TreeNode* root) {
    //     // 2-d Vector for storing the answer
    //     vector<vector<int>> arr;
    //     // if root is null return empty arr
    //     if(root == NULL) return arr;
    //     // For Storing the children
    //     queue<TreeNode*> q;
    //     // pushing the first level.
    //     q.push(root);
    //     // For storing the individual level.
    //     vector<int> level;
    //     // Until the queue is not empty go in the loop as there is some node which have to 
    //     // be processed.
    //     while(!q.empty()){
    //         // Only the current level has to be considered for this time so we take the size of the 
    //         // queue already..
    //         int n = q.size();
    //         for(int i = 0;i < n;i++){
    //             // Take the current node push into the level and then pushing the children into the 
    //             // queue. Popping the current node as well.
    //             TreeNode* current = q.front();
    //             level.push_back(current->val);
    //             if(current->left) q.push(current->left);
    //             if(current->right) q.push(current->right);
    //             q.pop();
    //         }
    //         // At the last add that level in to the 2-d vector.
    //         arr.push_back(level);
    //         level.clear();
    //     }
    //     // Reversing the levels from bottom to up fashion now.
    //     reverse(arr.begin(), arr.end());
    //     return arr;
    // }
    
    // 2) Using Queue and insert function for 2-d Vector(adding current level at the start). - Very Slow
    // vector<vector<int>> levelOrderBottom(TreeNode* root) {
    //     // 2-d Vector for storing the answer
    //     vector<vector<int>> arr;
    //     // if root is null return empty arr
    //     if(root == NULL) return arr;
    //     // For Storing the children
    //     queue<TreeNode*> q;
    //     // pushing the first level.
    //     q.push(root);
    //     // For storing the individual level.
    //     vector<int> level;
    //     // Until the queue is not empty go in the loop as there is some node which have to 
    //     // be processed.
    //     while(!q.empty()){
    //         // Only the current level has to be considered for this time so we take the size of the 
    //         // queue already..
    //         int n = q.size();
    //         for(int i = 0;i < n;i++){
    //             // Take the current node push into the level and then pushing the children into the 
    //             // queue. Popping the current node as well.
    //             TreeNode* current = q.front();
    //             level.push_back(current->val);
    //             if(current->left) q.push(current->left);
    //             if(current->right) q.push(current->right);
    //             q.pop();
    //         }
    //         // At the front add that current level in to the 2-d vector.
    //         arr.insert(arr.begin(), level);
    //         level.clear();
    //     }
    //     // Ultimately due to our unique of inserting the current levels at the first 
    //     // We already have the levels stored in the reverse order.
    //     return arr;
    // }
    
    // 3) Using Recursive Approach
    // For using Recursive approach we should understand that we require to know maximum depth 
    // of the Binary Tree.
    // Because we are finding the Maximum depth in O(n) time after that we don't use a queue for storing 
    // we insert it directly to the res vector.
    // Which saves our space.
//     int depth(TreeNode* root){
//         if(!root) return 0;
//         return 1 + max(depth(root->left), depth(root->right));
//     }
    
//     void helper(int level, TreeNode* root){
//         if(!root) return;
//         // If it is at ith level from the top then it is at (depth - 1 - i)th level at from the bottom
//         // We are using that concept here.
//         res[depth1 - level - 1].push_back(root->val);
//         if(root->left) helper(level + 1, root->left);
//         if(root->right) helper(level + 1, root->right);
//     }
    
//     vector<vector<int>> levelOrderBottom(TreeNode* root){
//         if(!root) return res;
//         depth1 = depth(root);
//         // Initialising the 2-d vector with depth1 rows and empty vectors.
//         res.assign(depth1, {});
//         helper(0, root);
//         return res;
//     }
    
//     private : 
//     vector<vector<int>> res;
//     int depth1;
    
    // 4) Using a queue and a 2-d Vector by calculating the maximum depth.
    
//     int depth(TreeNode* root){
//         if(!root) return 0;
//         return 1 + max(depth(root->left), depth(root->right));
//     }
    
//     vector<vector<int>> levelOrderBottom(TreeNode* root) {
//         // 2-d Vector for storing the answer
//         vector<vector<int>> arr;
//         // if root is null return empty arr
//         if(root == NULL) return arr;
//         // For Storing the children
//         int depth1 = depth(root);
//         arr.assign(depth1, {});
//         queue<TreeNode*> q;
//         // pushing the first level.
//         q.push(root);
//         // Until the queue is not empty go in the loop as there is some node which have to 
//         // be processed.
//         int level = 0;
//         while(!q.empty()){
//             // Only the current level has to be considered for this time so we take the size of the 
//             // queue already..
//             int n = q.size();
//             for(int i = 0;i < n;i++){
//                 // Take the current node push into the level and then pushing the children into the 
//                 // queue. Popping the current node as well.
//                 TreeNode* current = q.front();
//                 // For the current level we are storing the values in the (depth - 1 - level)th level as 
//                 // per the condition of the question..
//                 arr[depth1 - 1 - level].push_back(current->val);
//                 if(current->left) q.push(current->left);
//                 if(current->right) q.push(current->right);
//                 q.pop();
//             }
//             level++;
//         }
//         return arr;
//     }
    
    // 5) Using stack<vector<int>> and storing every level in it.
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        // 2-d Vector for storing the answer
        vector<vector<int>> arr;
        // if root is null return empty arr
        if(root == NULL) return arr;
        stack<vector<int>> st;
        queue<TreeNode*> q;
        // pushing the first level.
        q.push(root);
        // Until the queue is not empty go in the loop as there is some node which have to 
        // be processed.
        vector<int> level;
        while(!q.empty()){
            // Only the current level has to be considered for this time so we take the size of the 
            // queue already..
            int n = q.size();
            for(int i = 0;i < n;i++){
                // Take the current node push into the level and then pushing the children into the 
                // queue. Popping the current node as well.
                TreeNode* current = q.front();
                // For the current level we are storing the values in the (depth - 1 - level)th level as 
                // per the condition of the question..
                level.push_back(current->val);
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
                q.pop();
            }
            st.push(level);
            level.clear();
        }
        while(!st.empty()){
            auto it = st.top();
            st.pop();
            arr.push_back(it);
        }
        return arr;
    }
};
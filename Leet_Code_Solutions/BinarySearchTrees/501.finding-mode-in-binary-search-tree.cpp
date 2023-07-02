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
//     // Approach 1 : Using nums vector to store all the elements. Then returning the maximum frequency element(s).
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        nums.push_back(root->val);
        inorder(root->right);
        return;
    }
    
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        // We have filled our nums vector in non-decreasing order.
        // Now let's find the maximum frequency element(s).
        // I have a changing frequency considering the current element.
        int freq = 1;
        // This indicates the maximum Frequency element till now.
        int maxFreq = 1;
        // It is the current element under check.
        int curr = nums[0];
        vector<int> ans;
        // It is the maximum frequency element.
        ans.push_back(curr);
        for(int i = 1; i < nums.size();i++){
            // If my current element is equal to the curr increment the frequency of the curr
            if(curr == nums[i]){
                freq++;
            }
            // Else we have encountered a new element. 
            else
            {
                // Now check if the frequency of the curr element is equal to previous maxFreq then add the element
                // to modes vector. Take care that it is not the first element that is to be pushed.
                if(maxFreq == freq && i != 1){
                    ans.push_back(curr);
                }
                // If the current element has freq greater than maxfreq then clear the ans vector. and push this 
                // element. Update the maxFreq by freq...
                if(maxFreq < freq){
                    ans.clear();
                    ans.push_back(curr);
                    maxFreq = freq;
                }
                // now our current element would be update to nums[i] with it's frequency equal to 1.
                curr = nums[i];
                freq = 1;
            }
        }
        // Sometimes what happens is that we come out of the vector. and the last elements data is still remaining 
        // to be compared. So this comparision is done here. Make sure due to the given conditions above. 
        // nums.size() != 1 so that we don't push the first element twice.
        if(maxFreq == freq && nums.size() != 1){
            ans.push_back(curr);
        }
        if(maxFreq < freq){
            ans.clear();
            ans.push_back(curr);
        }
        // At the end return the ans vector.
        return ans;
    }
    private:
    vector<int> nums;
    
    // Approach 2 : Without using nums vector and only space that we use is recursion stack space.
    void inorder(TreeNode* root, int &maxFreq, int &freq, int &prev, vector<int> &ans){
        if(!root) return;
        inorder(root->left, maxFreq, freq, prev, ans);
        // the last visited element is the inorder predecessor which is same in this case, because we are in a BST
        // we will increase the freq of that element
        if(prev == root->val){
            freq++;
        }
        // If we encounter a new element then intialise the freq for that element as 1.
        else if(prev != root->val){
            freq = 1;
        }
        // if the current value's frequency exceeds the maxfreq then we clear the ans vector and then update the 
        // maxFreq as well
        if(freq > maxFreq){ //  && curr != root->val
            ans.clear();
            ans.push_back(root->val);
            maxFreq = freq;
        }
        else if(freq == maxFreq){
            ans.push_back(root->val);
        }
        int temp = prev;
        prev = root->val;
        inorder(root->right, maxFreq, freq, prev, ans);
        // prev = temp;
        return;
    }
    
    vector<int> findMode(TreeNode* root){
        vector<int> ans;
        int maxFreq = -1000000;
        int freq = -1000000;
        int prev = -1000000;
        inorder(root, maxFreq, freq, prev, ans);
        return ans;
    }
};
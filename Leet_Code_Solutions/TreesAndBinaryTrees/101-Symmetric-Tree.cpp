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
    bool isSame(TreeNode *p, TreeNode *q){
        if(p == NULL && q == NULL) return true;
        if(p != NULL && q != NULL && p->val == q->val){
            bool leftAns = isSame(p->left, q->right);
            bool rightAns = isSame(p->right, q->left);
            if(rightAns == true && leftAns == true) return true;
            else false;
        }
        return false; /**
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
            bool isSame(TreeNode *p, TreeNode *q)
            {
                if (p == NULL && q == NULL)
                    return true;
                if (p != NULL && q != NULL && p->val == q->val)
                {
                    bool leftAns = isSame(p->left, q->right);
                    bool rightAns = isSame(p->right, q->left);
                    if (rightAns == true && leftAns == true)
                        return true;
                    else
                        false;
                }
                return false;
            }

            bool isSymmetric(TreeNode *root)
            {
                return isSame(root->left, root->right);
            }
        };
    }
    
    bool isSymmetric(TreeNode* root) {
        return isSame(root->left, root->right);
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head)
    {
        // First I will create an array from it.
        // 1) Using Extra Space.
        //         vector<int> list;
        //         while(head){
        //             list.push_back(head->val);
        //             head = head->next;
        //         }

        //         TreeNode* ans = createBST(list, 0, list.size() - 1);

        //         return ans;

        // 2) Without using extra space.
        if (head == NULL)
        {
            return NULL;
        }

        if (head->next == NULL)
        {
            return new TreeNode(head->val);
        }

        ListNode *slow = head;
        ListNode *fast = head->next->next;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        TreeNode *temp = new TreeNode(slow->next->val);
        temp->right = sortedListToBST(slow->next->next);

        slow->next = NULL;
        temp->left = sortedListToBST(head);

        return temp;
    }

    TreeNode *createBST(vector<int> &list, int start, int end)
    {
        if (end < start)
            return NULL;

        int mid = (start + (end - start) / 2);

        TreeNode *ans = new TreeNode(list[mid]);
        ans->left = createBST(list, start, mid - 1);
        ans->right = createBST(list, mid + 1, end);

        return ans;
    }
};
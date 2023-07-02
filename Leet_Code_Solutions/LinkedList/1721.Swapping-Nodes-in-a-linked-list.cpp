/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode (int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        // Find the kth from the Last.
        // For that we use two pointers ahead and behind.
        // ahead pointer is k steps ahead of behind pointer.
        ListNode *behind = head, *ahead = head;
        for (int i = 0; i < k; i++)
        {
            ahead = ahead->next;
        }
        while (ahead)
        {
            ahead = ahead->next;
            behind = behind->next;
        }

        ListNode *lastk = behind;
        ListNode *startk = head;
        for (int i = 1; i < k; i++)
        {
            startk = startk->next;
        }

        int temp = startk->val;
        startk->val = lastk->val;
        lastk->val = temp;

        return head;
    }
};
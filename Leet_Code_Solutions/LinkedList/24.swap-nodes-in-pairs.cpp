/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() :  val(0) , next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        // Note : without modifying list node values.
        if (!head)
            return NULL;
        if (head && !(head->next))
            return head;

        ListNode *newHead = head->next;
        ListNode *tmp = head->next->next;
        head->next = swapPairs(tmp);
        newHead->next = head;
        return newHead;
    }
};
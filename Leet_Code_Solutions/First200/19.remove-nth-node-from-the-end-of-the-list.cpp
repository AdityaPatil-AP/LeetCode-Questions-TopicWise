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
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // ListNode* start = head;
        // int size = 0;
        // while(start){
        //     start = start->next;
        //     size++;
        // }
        // start = head;
        // int rem = size - n - 1;
        // if(rem == -1) return head->next;
        // while(rem--){
        //     start = start->next;
        // }
        // ListNode* newNext = start->next->next;
        // start->next->next = NULL;
        // // free(start->next);
        // start->next = newNext;
        // return head;

        // Single pass.
        // We will keep a fast pointer which will already be n steps ahead of our slow pointer.
        // Our aim is to find the pointer before the target pointer. Therefore we stop fast->next == NULL.

        ListNode *fast = head, *slow = head;

        for (int i = 0; i < n; i++)
            fast = fast->next; // went n steps ahead.
        if (!fast)
            return head->next;
        while (fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *temp = slow->next->next, *temp1 = slow->next;
        slow->next->next = NULL;
        delete temp1;
        slow->next = temp;
        return head;
    }
};
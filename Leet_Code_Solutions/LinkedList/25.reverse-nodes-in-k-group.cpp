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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        // Note : Do Without Modifying the values.

        // 1) Recursive Way
        //         ListNode* cursor = head;
        //         for(int i = 0;i < k;i++){
        //             if(!cursor) return head;
        //             cursor = cursor->next;
        //         }

        //         // Use three pointers for reversing in Linked List.
        //         ListNode* curr = head;
        //         ListNode* prev = nullptr;
        //         ListNode* nxt = nullptr;
        //         for(int i = 0;i < k;i++){
        //             nxt = curr->next;
        //             curr->next = prev;
        //             prev = curr;
        //             curr = nxt;
        //         }

        //         head->next = reverseKGroup(curr, k);
        //         return prev;

        // Iterative Way.
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *after = head;
        ListNode *before = dummy;
        ListNode *curr = NULL, *prev = NULL, *nxt = NULL;
        while (true)
        {
            ListNode *cursor = after;
            for (int i = 0; i < k; i++)
            {
                if (!cursor)
                    return dummy->next;
                cursor = cursor->next;
            }

            curr = after;
            prev = before;
            for (int i = 0; i < k; i++)
            {
                nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }

            after->next = curr;
            before->next = prev;
            before = after;
            after = curr;
        }
    }
};
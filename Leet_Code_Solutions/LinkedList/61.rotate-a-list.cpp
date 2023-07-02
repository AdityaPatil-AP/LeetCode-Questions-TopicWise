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
    ListNode *rotateRight(ListNode *head, int k)
    {

        if (head == NULL || head->next == NULL)
            return head;

        k = k % listSize(head);

        // if there is no shifting, then return the linked list as it is.
        if (k == 0)
            return head;

        ListNode *behind = head;
        ListNode *ahead = head;

        while (k--)
        {
            ahead = ahead->next;
        }

        while (ahead->next != NULL)
        {
            ahead = ahead->next;
            behind = behind->next;
        }

        ListNode *newHead = behind->next;
        behind->next = NULL;
        ahead->next = head;
        return newHead;
    }

    int listSize(ListNode *head)
    {
        int size = 0;
        ListNode *temp = head;
        while (temp)
        {
            size++;
            temp = temp->next;
        }

        return size;
    }
};
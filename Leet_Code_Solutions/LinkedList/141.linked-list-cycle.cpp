/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        // To check if there is a cycle in single linked list. We have to use slow and fast
        // pointers.

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow)
            {
                return true;
            }
        }

        return false;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == NULL)
            return false;
        ListNode *ahead = head->next;
        ListNode *behind = head;

        while (ahead != NULL && ahead->next != NULL)
        {
            if (ahead == behind)
            {
                return true;
            }

            ahead = ahead->next->next;
            behind = behind->next;
        }

        return false;
    }
};
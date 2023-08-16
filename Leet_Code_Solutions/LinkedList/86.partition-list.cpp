class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode after(0), before(0);

        ListNode *after_curr = &after;
        ListNode *before_curr = &before;

        while (head)
        {
            if (head->val < x)
            {
                before_curr->next = head;
                before_curr = head;
            }
            else
            {
                after_curr->next = head;
                after_curr = head;
            }

            head = head->next;
        }

        after_curr->next = nullptr;
        before_curr->next = after.next;

        return before.next;
    }
};

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution
{
public
    ListNode partition(ListNode head, int x)
    {
        ListNode after = new ListNode(0);
        ListNode before = new ListNode(0);

        ListNode after_curr = after;
        ListNode before_curr = before;

        while (head != null)
        {
            if (head.val < x)
            {
                before_curr.next = head;
                before_curr = head;
            }
            else
            {
                after_curr.next = head;
                after_curr = head;
            }

            head = head.next;
        }

        after_curr.next = null;
        before_curr.next = after.next;

        return before.next;
    }
}
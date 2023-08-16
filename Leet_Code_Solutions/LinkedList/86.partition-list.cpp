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
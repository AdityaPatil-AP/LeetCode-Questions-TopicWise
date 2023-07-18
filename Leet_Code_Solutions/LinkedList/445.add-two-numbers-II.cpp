class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *next;
        while (head)
        {
            // Store the next node.
            next = head->next;

            // Reversing the link.
            head->next = prev;

            // Update the previous node and the current node.
            prev = head;
            head = next;
        }

        return prev;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        ListNode *r1 = reverseList(l1);
        ListNode *r2 = reverseList(l2);

        // Simple sum.
        ListNode *ans = new ListNode();
        int carry = 0;

        while (r1 != NULL || r2 != NULL || carry)
        {
            int totalSum = 0;
            if (r1)
            {
                totalSum += r1->val;
                r1 = r1->next;
            }
            if (r2)
            {
                totalSum += r2->val;
                r2 = r2->next;
            }

            totalSum += carry;

            carry = totalSum / 10;
            int curr = totalSum % 10;
            ListNode *head = new ListNode();
            ans->val = curr;
            head->next = ans;
            ans = head;
        }

        return ans->next;
    }
};
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

        // Using Stack as Well.
        stack<int> s1, s2;

        while (l1)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0;
        ListNode *ans = new ListNode();
        while (!s1.empty() || !s2.empty())
        {
            int totalSum = 0;
            if (!s1.empty())
            {
                totalSum += s1.top();
                s1.pop();
            }
            if (!s2.empty())
            {
                totalSum += s2.top();
                s2.pop();
            }

            totalSum += carry;

            int curr = totalSum % 10;
            carry = totalSum / 10;

            ListNode *head = new ListNode(carry);
            ans->val = curr;
            head->next = ans;
            ans = head;
        }

        return (carry == 0) ? ans->next : ans;

        // Reversing the Linked List.
        // ListNode* r1 = reverseList(l1);
        // ListNode* r2 = reverseList(l2);

        // // Simple sum.
        // ListNode* ans = new ListNode();
        // int carry = 0;

        // while(r1 != NULL || r2 != NULL || carry){
        //     int totalSum = 0;
        //     if(r1){
        //         totalSum += r1->val;
        //         r1 = r1->next;
        //     }
        //     if(r2){
        //         totalSum += r2->val;
        //         r2 = r2->next;
        //     }

        //     totalSum += carry;

        //     carry = totalSum/10;
        //     int curr = totalSum % 10;
        //     ListNode* head = new ListNode();
        //     ans->val = curr;
        //     head->next = ans;
        //     ans = head;
        // }

        // return ans->next;
    }
};
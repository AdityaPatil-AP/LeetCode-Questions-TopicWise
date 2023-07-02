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
    ListNode *detectCycle(ListNode *head)
    {
        // 2 Methods to solve.

        // 1) Using Hashmap.
        // map<ListNode*, int> mp;
        // ListNode* ans = head;
        // while(ans){
        //     mp[ans]++;
        //     if(mp[ans] == 2){
        //         return ans;
        //     }
        //     ans = ans->next;
        // }
        // return NULL;

        // Using Floyd's Detection Algorithm.
        if (head == NULL)
            return NULL;

        ListNode *slow = head;
        ListNode *fast = head;

        while (slow && fast)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast)
                fast = fast->next;
            if (fast == slow)
                break;
        }

        // If we reach the end of the linked list then there is no cycle.
        if (!fast)
            return NULL;

        // Other wise there is a cycle, we are at a common meeting point.
        // Now the distance from the head and the common meeting point to the start of the linked list is same.
        // So we move that much steps ahead.

        ListNode *temp = head;
        while (temp != slow)
        {
            slow = slow->next;
            temp = temp->next;
        }

        return temp;
    }
};
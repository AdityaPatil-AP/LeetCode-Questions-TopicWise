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
    //     Iterative Way of Solving
    // ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    //     int sum = 0;
    //     ListNode newHead(0);
    //     ListNode* t = &newHead;
    //     while(l1 != NULL || l2 != NULL || sum){
    //         sum += (l1?l1->val:0) + (l2?l2->val:0);
    //         t->next = new ListNode(sum%10);
    //         t = t->next;
    //         sum /= 10;
    //         if(l1) l1 = l1->next;
    //         if(l2) l2 = l2->next;
    //     }
    //     return newHead.next;
    // }

    //     Recursion
    // ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    //     if(!l1 && !l2){
    //         return NULL;
    //     }
    //     int sum = (l1?l1->val:0) + (l2?l2->val:0);
    //     ListNode* newHead = new ListNode(sum%10), *next = (l1?l1->next:NULL);
    //     sum /= 10;
    //     if(next) next->val += sum;
    //     else if(sum) next = new ListNode(sum);
    //     newHead->next = addTwoNumbers(next, (l2?l2->next:NULL));
    //     return newHead;
    // }

    // Practice - 2nd time..
    // Iterative Way.
    // ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    //     int sum = 0;
    //     ListNode newHead(0);
    //     ListNode *t = &newHead;
    //     while(l1 || l2 || sum){
    //         sum += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
    //         t->next = new ListNode(sum%10);
    //         sum /= 10;
    //         t = t->next;
    //         if(l1) l1 = l1->next;
    //         if(l2) l2 = l2->next;
    //     }
    //     return newHead.next;
    // }

    // Recursive Way
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (!l1 && !l2)
        {
            return NULL;
        }
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
        ListNode *newHead = new ListNode(sum % 10), *next = (l1 ? l1->next : NULL);

        sum = sum / 10;
        if (next)
            next->val += sum;
        else if (sum)
            next = new ListNode(sum);
        newHead->next = addTwoNumbers(next, (l2 ? l2->next : NULL));
        return newHead;
    }
};
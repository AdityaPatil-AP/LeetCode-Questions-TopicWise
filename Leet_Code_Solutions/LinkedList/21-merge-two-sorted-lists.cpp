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
    // Recursive Approach.
    // ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
    //     if(!list1) return list2;
    //     if(!list2) return list1;
    //     ListNode* res;
    //     if(list1->val <= list2->val){
    //         res = list1;
    //         res->next = mergeTwoLists(list1->next,list2);
    //     }
    //     else{
    //         res = list2;
    //         res->next = mergeTwoLists(list1, list2->next);
    //     }
    //     return res;
    // }

    // Iterative Approach.
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (!list1)
            return list2;
        if (!list2)
            return list1;
        ListNode *ptr, *curr;
        ListNode *l1 = list1, *l2 = list2;
        if (l1->val <= l2->val)
        {
            ptr = l1;
            l1 = l1->next;
        }
        else
        {
            ptr = l2;
            l2 = l2->next;
        }
        curr = ptr;
        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                curr->next = l1;
                l1 = l1->next;
            }
            else
            {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if (!l1)
            curr->next = l2;
        else
            curr->next = l1;
        return ptr;
    }
};
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

    struct node
    {
        ListNode *curr; // current node.
        int index;      // List Index Number;
        node(ListNode *a, int b)
        {
            curr = a;
            index = b;
        }
    };

    class compare
    {
    public:
        bool operator()(node a, node b)
        {
            return (a.curr->val > b.curr->val);
        }
    };

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        // Brute Force. -- add all the elements into the array and then sort it.
        // After sorting create a linked list out of it.
        // if(lists.size() == 0) return NULL;
        // vector<int> arr;
        // for(auto list : lists){
        //     while(list){
        //         arr.push_back(list->val);
        //         list = list->next;
        //     }
        // }
        // if(arr.size() == 0) return NULL;
        // // Creating a linked list.
        // sort(arr.begin(), arr.end());
        // ListNode* head = new ListNode(arr[0]);
        // ListNode* curr = head;
        // for(int i = 1;i < arr.size();i++){
        //     curr->next = new ListNode(arr[i]);
        //     curr = curr->next;
        // }
        // return head;

        // Time Complexity - O(n*log(n)) 1) O(n) + O(n*log(n)) + O(n).
        // Space Complexity - O(n) | O(n) - Sorting Algorithm + O(n) - for creating the linked list.

        // 2) Compare one by one.
        // 3) Merging lists one by one.

        // 4) Divide and Conquer.
        //         int k = lists.size();
        //         if(k == 0) return NULL;
        //         if(k == 1) return lists[0];
        //         ListNode* head = mergeLists(lists, 0, k - 1);
        //         return head;
        //     }

        //     ListNode* mergeLists(vector<ListNode*> &lists, int start, int end){
        //         if(start == end){
        //             return lists[start];
        //         }

        //         ListNode* head, *h1, *h2;
        //         int k = end - start + 1;
        //         h1 = mergeLists(lists, start, start + k/2 - 1);
        //         h2 = mergeLists(lists, start + k/2, end);

        //         head = merge(h1, h2);
        //         return head;
        //     }

        //     ListNode* merge(ListNode* h1, ListNode* h2){
        //         if(!h1 && !h2) return NULL;
        //         if(!h1) return h2;
        //         if(!h2) return h1;

        //         ListNode* head, *ptr;
        //         if(h1->val <= h2->val){
        //             head = h1;
        //             h1 = h1->next;
        //         }
        //         else{
        //             head = h2;
        //             h2 = h2->next;
        //         }
        //         ptr = head;
        //         while(h1 || h2){
        //             if(!h1){
        //                 ptr->next = h2;
        //                 h2 = h2->next;
        //             }
        //             else if(!h2){
        //                 ptr->next = h1;
        //                 h1 = h1->next;
        //             }
        //             else if(h1->val <= h2->val){
        //                 ptr->next = h1;
        //                 h1 = h1->next;
        //             }
        //             else{
        //                 ptr->next = h2;
        //                 h2 = h2->next;
        //             }

        //             ptr = ptr->next;
        //         }
        //         return head;
        //     }

        // 5) Using Min Heap.
        int k = lists.size();
        if (k == 0)
            return NULL;
        ListNode *head, *tail;
        priority_queue<node, vector<node>, compare> heap;
        vector<ListNode *> ptr(k); // Current Node Pointer from all the lists.
        // Assign all the current ptrs and build heap.
        for (int i = 0; i < k; i++)
        {
            ptr[i] = lists[i];
            if (ptr[i])
            {
                heap.push(node(ptr[i], i));
            }
        }

        if (heap.empty())
        {
            return NULL;
        }

        head = tail = heap.top().curr;
        int index = heap.top().index;
        heap.pop();
        ptr[index] = ptr[index]->next;
        if (ptr[index])
        {
            heap.push(node(ptr[index], index));
        }

        // Make list with rest of the nodes.
        while (!heap.empty())
        {
            ListNode *temp = heap.top().curr; // Pop the topmost node.
            index = heap.top().index;
            heap.pop();

            // Add to the list.
            tail->next = temp;
            tail = tail->next;
            ptr[index] = ptr[index]->next; // Update current pointer.
            if (ptr[index])
            { // Push Newly pointed node if not null.
                heap.push(node(ptr[index], index));
            }
        }

        return head;
    }
};
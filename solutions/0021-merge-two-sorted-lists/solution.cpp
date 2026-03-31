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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if (list1 == NULL) return list2;

        if(list2 == NULL) return list1;

        // Head of merged list
        ListNode* head = NULL;
        // Tail pointer to build the list
        ListNode* tail = NULL;

        ListNode* h1 = list1;
        ListNode* h2 = list2;

        // Merge while both lists have nodes
        while (h1 && h2) {

            // Pick smaller node
            ListNode* chosen;
            if (h1->val <= h2->val) {
                chosen = h1;
                h1 = h1->next;
            } else {
                chosen = h2;
                h2 = h2->next;
            }

            if (head == NULL) {
                head = chosen;
                tail = chosen;
            } 
            // Attach node to merged list
            else {
                tail->next = chosen;
                tail = tail->next;
            }
        }

        // Attach remaining nodes
        if (h1) tail->next = h1;
        if (h2) tail->next = h2;

        return head;
    }
};

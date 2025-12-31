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
    ListNode* oddEvenList(ListNode* head) {
        
        // Edge cases
        if (!head || !head->next) return head;

        ListNode* odd = head;              // starts at 1st node
        ListNode* even = head->next;       // starts at 2nd node
        ListNode* evenHead = even;          // save start of even list

        while (even && even->next) {
            odd->next = even->next;        // link odd to next odd
            odd = odd->next;

            even->next = odd->next;        // link even to next even
            even = even->next;
        }

        odd->next = evenHead;               // attach even list after odd list
        
        return head; 

    }
};

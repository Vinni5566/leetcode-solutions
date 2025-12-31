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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode dummy(0);          // dummy head for result list
        ListNode* tail = &dummy;    // pointer to build the list
        int carry = 0;              // carry for addition

        while (l1 || l2 || carry) {
            int sum = carry;        // start with carry from previous step
            
            if (l1) {
                sum += l1->val;    // add digit from l1
                l1 = l1->next;     // move to next node
            }
            if (l2) {
                sum += l2->val;    // add digit from l2
                l2 = l2->next;     // move to next node
            }

            carry = sum / 10;                 // update carry
            tail->next = new ListNode(sum % 10); // create new node with single digit
            tail = tail->next;                // move tail
        }

        return dummy.next;  // return head of the result list
        
    }
};

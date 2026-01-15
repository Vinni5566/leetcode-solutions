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

        //reverse both linked list
        //add reversed numbers linked list
        //again reverse the sum linked list
        
        ListNode* r1 = reverse(l1);
        ListNode* r2 = reverse(l2);

        ListNode* revAddition = addNumbers(r1, r2);

        return reverse(revAddition);


    }

    ListNode* addNumbers(ListNode* head1, ListNode* head2) {

        ListNode dummy(0);
        ListNode* tail = &dummy;
        int carry = 0;

        while(head1 || head2 || carry) {

            int sum = carry;

            if(head1) {
                sum += head1->val;
                head1 = head1->next;
            }

            if(head2) {
                sum += head2->val;
                head2 = head2->next;
            }

            carry = sum/10;
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
        }

        return dummy.next;
    }

    ListNode* reverse(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while(curr != NULL) {

            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};

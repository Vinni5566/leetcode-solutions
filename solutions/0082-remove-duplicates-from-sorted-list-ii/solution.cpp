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
    ListNode* deleteDuplicates(ListNode* head) {

        if(head == NULL || head->next == NULL) return head;

        ListNode* curr = head;

        ListNode* newHead = NULL;
        ListNode* tail = NULL;

        while(curr != NULL) {

            bool isDuplicate = false;

            while(curr->next != NULL && curr->val == curr->next->val) {
                curr = curr->next;
                isDuplicate = true;
            }

            if(!isDuplicate) {
                if(!newHead) {
                    newHead = curr;
                    tail = curr;
                } else {
                    tail->next = curr;
                    tail = tail->next;
                }
            }

            curr = curr->next;
        }

        if(newHead != NULL) tail->next = NULL;

        return newHead;
        
    }
};

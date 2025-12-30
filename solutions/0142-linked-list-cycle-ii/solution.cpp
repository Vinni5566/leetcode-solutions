/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {  //cycle detected
                ListNode* ptr = head;
                while(ptr != slow) { 
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr; //starting point
            }
        }

        //no cycle
        return NULL;
        
    }
};

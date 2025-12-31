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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if (!head || k == 1) return head;

        //dummy node to simplify head changes
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroup = &dummy;

        while (true) {
            //check if there are at least k nodes left
            ListNode* kth = prevGroup;
            for (int i = 0; i < k && kth; i++) {
                kth = kth->next;
            }
            if (!kth) break; //less than k nodes left, done

            //reverse k nodes
            ListNode* groupPrev = prevGroup->next;
            ListNode* curr = groupPrev->next;
            ListNode* nextNode;

            for (int i = 1; i < k; i++) {
                nextNode = curr->next;
                curr->next = prevGroup->next;
                prevGroup->next = curr;
                curr = nextNode;
            }

            groupPrev->next = curr;  //connect to next group
            prevGroup = groupPrev;    //move prevGroup to end of reversed group
        }

        return dummy.next;

    }
};

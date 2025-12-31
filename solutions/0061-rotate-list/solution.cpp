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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if (!head || !head->next || k == 0) return head;

        //find length and last node
        ListNode* curr = head;
        int n = 1;
        while (curr->next) {
            curr = curr->next;
            n++;
        }

        //make it circular
        curr->next = head;

        //find new tail and new head
        k = k % n; //handle k > n
        int stepsToNewTail = n - k - 1;
        ListNode* newTail = head;
        for (int i = 0; i < stepsToNewTail; i++) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;

        //break the circle
        newTail->next = nullptr;

        return newHead;

    }
};

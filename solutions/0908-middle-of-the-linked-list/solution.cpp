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
    ListNode* middleNode(ListNode* head) {
        
        int l = 0;

        ListNode* temp = head;

        while(temp != NULL) {
            temp = temp->next;
            l++;
        }

        int mid = l/2;

        temp = head;

        while(mid > 0) {
            temp = temp->next;
            mid--;
        }

        return temp;
    }
};

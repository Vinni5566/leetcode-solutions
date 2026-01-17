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
    ListNode* sortList(ListNode* head) {
        
        vector<int> sorted;

        ListNode* temp = head;

        while(temp != NULL) {
            sorted.push_back(temp->val);
            temp = temp->next;
        }

        sort(sorted.begin(), sorted.end());

        ListNode* newHead = NULL;
        ListNode* tail = NULL;

        for(int i = 0; i < sorted.size(); i++) {

            ListNode* node = new ListNode(sorted[i]);

            if(newHead == NULL) {
                newHead = node;
                tail = node;
            } else {
                tail->next = node;
                tail = node;
            }
        }

        return newHead;
    }
};

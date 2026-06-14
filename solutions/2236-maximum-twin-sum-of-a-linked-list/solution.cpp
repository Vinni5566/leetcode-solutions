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
    int pairSum(ListNode* head) {
        
        vector<int> nodes;
        int n = 0;

        ListNode* temp = head;

        while(temp != NULL) {
            nodes.push_back(temp->val);
            temp = temp->next;
            n++;
        }

        int res = 0;

        for(int i = 0; i < n/2; i++) {   
            int twinVal = nodes[i] + nodes[n-i-1];
            res = max(res, twinVal);
        }

        return res;
    }
};

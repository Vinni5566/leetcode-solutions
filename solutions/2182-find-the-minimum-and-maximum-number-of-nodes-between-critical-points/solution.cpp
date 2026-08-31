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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        if(head->next->next == NULL) return {-1, -1};

        vector<int> critical_indexes;

        ListNode* prev = head;
        ListNode* curr = head->next;

        int idx = 2;

        while(curr->next != NULL) {
            int current = curr->val;
            int nxt = curr->next->val;
            int previous = prev->val;

            if(current > nxt && current > previous) {
                critical_indexes.push_back(idx);
            } else if(current < nxt && current < previous) {
                critical_indexes.push_back(idx);
            }

            idx++;

            prev = curr;
            curr = curr->next;
        }

        int n = (int) critical_indexes.size();

        if(critical_indexes.size() < 2) return {-1, -1};

        int maxNodes = critical_indexes[n-1] - critical_indexes[0];
        int minNodes = INT_MAX;

        for (int i = 1; i < critical_indexes.size(); i++) {
            minNodes = min(minNodes, critical_indexes[i] - critical_indexes[i - 1]);
        }

        return {minNodes,maxNodes};
    }
};

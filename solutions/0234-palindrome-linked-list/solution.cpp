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
#include <stack>

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;

        std::stack<int> s;
        ListNode* curr = head;

        // Push all values onto the stack
        while (curr != nullptr) {
            s.push(curr->val);
            curr = curr->next;
        }

        // Compare stack (reverse order) with linked list (original order)
        curr = head;
        while (curr != nullptr) {
            if (curr->val != s.top()) {
                return false;
            }
            s.pop();
            curr = curr->next;
        }

        return true;
    }
};


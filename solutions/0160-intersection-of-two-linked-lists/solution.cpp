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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if (!headA || !headB) return nullptr;

        //calculate lengths
        int lenA = 0, lenB = 0;
        ListNode* a = headA;
        ListNode* b = headB;

        while (a) { lenA++; a = a->next; }
        while (b) { lenB++; b = b->next; }

        //reset pointers
        a = headA;
        b = headB;

        //move pointer of longer list ahead
        if (lenA > lenB) {
            int diff = lenA - lenB;
            while (diff--) a = a->next;
        } else {
            int diff = lenB - lenA;
            while (diff--) b = b->next;
        }

        //move both pointers together
        while (a && b) {
            if (a == b) return a;   //intersection found
            a = a->next;
            b = b->next;
        }

        return nullptr; //no intersection
    }
};

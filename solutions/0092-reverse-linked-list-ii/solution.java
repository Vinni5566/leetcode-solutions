/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseBetween(ListNode head, int left, int right) {
        if (head == null || left == right) return head;
        ListNode temp = new ListNode(0);
        temp.next=head;
        ListNode prevL=temp;
        for (int i=1;i<left;i++) {
            prevL=prevL.next;
        }
        ListNode start=prevL.next;
        ListNode curr=start;
        ListNode prev=null;
        for (int i=left;i<=right;i++) {
            ListNode nextNode=curr.next;
            curr.next=prev;
            prev=curr;
            curr=nextNode;
        }
        prevL.next=prev;
        start.next=curr;
        return temp.next;
    }
}

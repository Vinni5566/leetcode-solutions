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
    public ListNode deleteMiddle(ListNode head) {
        if (head == null || head.next == null) {
            return null;
        }
        ListNode curr=head;
        int size=0;
        while (curr!=null) {
            size++;
            curr=curr.next;
        }
        int middleIndex=size/2;
        curr=head;
        int count=0;
        while(count<middleIndex-1) {
            count++;
            curr=curr.next;
        }
        if(curr!=null && curr.next!=null) {
            curr.next=curr.next.next;
        }
        return head;
    }
}


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
    public ListNode sortList(ListNode head) {
        int length = 0;
        ListNode current = head;
        while (current != null) {
            length++;
            current = current.next;
        }
        int[] arr = new int[length];
        current = head;
        int index = 0;
        while (current != null) {
            arr[index++] = current.val;
            current = current.next;
        }
        Arrays.sort(arr);
        ListNode newHead = new ListNode(0);
        ListNode newCurr = newHead;
        for (int i = 0; i < arr.length; i++) {
            newCurr.next = new ListNode(arr[i]);
            newCurr = newCurr.next;
        }
        return newHead.next;
    }
}

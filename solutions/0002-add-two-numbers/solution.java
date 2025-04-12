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
import java.math.BigInteger;
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        StringBuilder s1 = new StringBuilder();
        StringBuilder s2 = new StringBuilder();

        ListNode t1 = l1;
        ListNode t2 = l2;

        while(t1 != null) {
            s1.append(t1.val);
            t1 = t1.next;
        }

        while(t2 != null) {
            s2.append(t2.val);
            t2 = t2.next;
        }

        BigInteger n1 = new BigInteger(s1.reverse().toString());
        BigInteger n2 = new BigInteger(s2.reverse().toString());

        BigInteger sum = n1.add(n2);

        String sumStr = sum.toString();

        ListNode dummy = new ListNode(0);
        ListNode temp = dummy;

        for (int i = sumStr.length() - 1; i >= 0; i--) {
            temp.next = new ListNode(sumStr.charAt(i) - '0');
            temp = temp.next;
        }

        return dummy.next;
    }
}

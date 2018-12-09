/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if (l1 == null || l2 == null) {
            return null;
        }
        
        ListNode res = new ListNode(0);
        res.next = null;
        
        ListNode p1 = l1, p2 = l2, pr = res;
        int carry = 0;
        
        while (p1 != null || p2 != null || carry != 0) {
            pr.val += carry;
            
            if (p1 != null) {
                pr.val += p1.val;
                p1 = p1.next;
            }
            if (p2 != null) {
                pr.val += p2.val;
                p2 = p2.next;
            }
            
            carry = pr.val / 10;
            pr.val = pr.val % 10;
            
            if (p1 != null || p2 != null || carry != 0) {
                pr.next = new ListNode(0);
                pr = pr.next;
                pr.next = null;
            }
        }
        return res;
    }
}

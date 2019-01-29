/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isPalindrome(ListNode head) {
        // O(n) time, O(1) space
        
        ListNode prev, backup, slow, fast;
        slow = fast = head;
        prev = null;
        
        // use two pointers to find the middle of linked list
        // and reverse the first half of lists
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            backup = slow.next;
            slow.next = prev;
            prev = slow;
            slow = backup;
        }
        
        // check if number of nodes is odd
        if (fast != null) {
            slow = slow.next;
        }
        
        // pointers now are like so
        //        prev slow        fast
        //  0 <-1 <-2   3-> 4-> 5-> null
        
        // check from middle to both ends
        while (slow != null) {
            if (prev.val != slow.val) {
                return false;
            }
            prev = prev.next;
            slow = slow.next;
        }
        
        return true;
    }
}

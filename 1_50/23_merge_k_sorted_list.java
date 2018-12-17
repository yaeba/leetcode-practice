/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

import java.util.PriorityQueue;

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0) {
            return null;
        } else if (lists.length == 1) {
            return lists[0];
        }
        
        ListNode res = new ListNode(0);
        ListNode p = res;
        
        PriorityQueue<ListNode> queue = new PriorityQueue<>(new Comparator<ListNode>(){
            public int compare(ListNode l1, ListNode l2) {
                return l1.val - l2.val;
            }
        });
        
        for (ListNode list : lists) {
            if (list != null) {
                queue.add(list);
            }
        }
        
        while (!queue.isEmpty()) {
            ListNode head = queue.poll();
            p.next = head;
            p = p.next;
            if (head.next != null) {
                queue.add(head.next);
            }
        }
        
        return res.next;
    }
}

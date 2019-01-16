/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
  if (head == NULL) {
    return head;
  }
    
  // O(n) time, O(1) space
  // use two pointers that are n nodes apart
  struct ListNode *start = head;
  struct ListNode *end = head;
    
    
  // advance pointer by (n+1) steps
  for (int i=0; i<=n; i++) {
    if (end == NULL) {
      // edge case
      return head->next;
    }
    end = end->next;
  }
    
  // advance both pointers together
  while (end != NULL) {
    start = start->next;
    end = end->next;
  }
    
  // removing the nth node
  start->next = start->next->next;
    
  return head;
}

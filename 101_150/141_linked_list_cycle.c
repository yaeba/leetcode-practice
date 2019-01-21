/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
  if (head == NULL || head->next == NULL) {
    return false;
  }
    
  // O(n) time, O(1) space
  // using two pointers, one moves 1 step at a time,
  // while the other moves 2 steps at a time
    
  struct ListNode *slow = head;
  struct ListNode *fast = head;
    
  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
        
    if (slow == fast) {
      // linked list has cycle if they collide
      return true;
    }
  }
    
  // fast has reached the end of linked list
  return false;
}

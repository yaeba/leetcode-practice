/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *createNode() {
    struct ListNode *new = malloc(sizeof(struct ListNode));
    new->val = 0;
    new->next = NULL;
    return new;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // safety measure
    if (l1 == NULL || l2 == NULL) {
        return NULL;
    }
    
    struct ListNode *res = createNode();
    
    struct ListNode *p1 = l1, *p2 = l2, *pr = res;
    int carry = 0;
    
    while (p1 != NULL || p2 != NULL || carry != 0) {
        // add any carry over
        pr->val += carry;
            
        // add two digits of l1 and l2
        if (p1 != NULL) {
            pr->val += p1->val;
            p1 = p1->next;
        }
        if (p2 != NULL) {
            pr->val += p2->val;
            p2 = p2->next;
        }
        
        // compute any carry over
        carry = pr->val / 10;
        pr->val = pr->val % 10;
        
        if (p1 != NULL || p2 != NULL || carry != 0) {
            pr->next = createNode();
            pr = pr->next;
        }
    }
    return res;
}

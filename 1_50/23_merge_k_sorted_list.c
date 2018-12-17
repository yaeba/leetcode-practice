/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *res = malloc(sizeof(struct ListNode));
    struct ListNode *p = res;
    while ((l1) && (l2)) {
        if (l1->val < l2->val) {
            p->next = l1;
            l1 = l1->next;
        } else {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    // add the remaining values
    p->next = l1 ? l1 : l2;
    return res->next;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (lists == NULL || listsSize == 0) {
        return NULL;
    } else if (listsSize == 1) {
        return lists[0];
    }
    
    int last = listsSize - 1;
    
    while (last > 0) {
        // merge first and last
        int i = 0, j = last;
        
        // (lists[i], lists[j]) is a pair
        while (i < j) {
            lists[i] = mergeTwoLists(lists[i], lists[j]);
            i++;
            j--;
        }
        
        // update index of last
        last = j;
    }
    // return the one remaining
    return lists[0];
}

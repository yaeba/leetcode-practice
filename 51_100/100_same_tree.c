/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL) {
        return true;
    } else if (p == NULL || q == NULL) {
        // one of them is null
        return false;
    }
    // recursively check left part and right part of tree
    return (p->val == q->val) &&
        (isSameTree(p->left, q->left)) &&
        (isSameTree(p->right, q->right));
}

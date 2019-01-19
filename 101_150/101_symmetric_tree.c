/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isSymmetricR(struct TreeNode *l, struct TreeNode *r) {
  // base case
  if (l == NULL && r == NULL) {
    return true;
  } else if (l == NULL || r == NULL) {
    return false;
  }
    
    return l->val == r->val &&
      isSymmetricR(l->left, r->right) &&
      isSymmetricR(l->right, r->left);
}

bool isSymmetric(struct TreeNode* root) {
  return isSymmetricR(root, root);
}

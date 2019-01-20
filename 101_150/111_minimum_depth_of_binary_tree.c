/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int minDepth(struct TreeNode* root) {
  if (root == NULL) {
    return 0;
  }
  int leftDepth = minDepth(root->left);
  int rightDepth = minDepth(root->right);
  return (leftDepth == 0 || rightDepth == 0) ?
    leftDepth + rightDepth + 1 : MIN(leftDepth, rightDepth) + 1;
}

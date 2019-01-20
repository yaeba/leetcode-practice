/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define UNBALANCED INT_MAX
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int getHeight(struct TreeNode *tree) {
  if (tree == NULL) {
    // base case
    return 0;
  }
    
  int leftHeight = getHeight(tree->left);
  if (leftHeight == UNBALANCED) return UNBALANCED;
  int rightHeight = getHeight(tree->right);
  if (rightHeight == UNBALANCED) return UNBALANCED;
    
  return (abs(leftHeight - rightHeight) > 1) ? 
    UNBALANCED : 1 + MAX(leftHeight, rightHeight);
}
bool isBalanced(struct TreeNode* root) {
  if (root == NULL) {
    return true;
  }
  return getHeight(root) != UNBALANCED;
}

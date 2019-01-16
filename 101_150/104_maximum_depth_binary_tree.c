/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
  if (root == NULL) {
    return 0;
  }
    
  int leftDepth = 1 + maxDepth(root->left);
  int rightDepth = 1 + maxDepth(root->right);
    
  return leftDepth > rightDepth ? leftDepth : rightDepth;
}

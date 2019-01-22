/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int sum) {
    
  // O(n) time, O(n) space
  if (root == NULL) {
    return false;
  } else if (root->left == NULL && root->right == NULL) {
    // reach leaf node
    return root->val == sum;
  } else {
    // continue down the path
    return hasPathSum(root->left, sum - root->val) 
      || hasPathSum(root->right, sum - root->val);
  }
}

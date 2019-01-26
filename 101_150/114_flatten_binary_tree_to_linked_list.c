/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void flatten(struct TreeNode* root) {
    struct TreeNode *curr = root;
    
    while (curr != NULL) {
        if (curr->left != NULL) {
            
            // find node precedes curr's right
            struct TreeNode *prev = curr->left;
            while (prev->right != NULL) {
                prev = prev->right;
            }
            
            prev->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
            
        }
        
        curr = curr->right;
    }
}

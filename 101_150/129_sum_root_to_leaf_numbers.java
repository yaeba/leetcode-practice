/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    private int sumNumbersR(TreeNode tree, int sum) {
        if (tree == null) {
            // only one node is null
            return 0;
        }
        
        int newSum = 10 * sum + tree.val;
        if (tree.left == null && tree.right == null) {
            // reach the leaf, return root-to-leaf number
            return newSum;
        }
        
        return sumNumbersR(tree.left, newSum) + 
            sumNumbersR(tree.right, newSum);
    }
    
    public int sumNumbers(TreeNode root) {
        // dfs
        return sumNumbersR(root, 0);
    }
}

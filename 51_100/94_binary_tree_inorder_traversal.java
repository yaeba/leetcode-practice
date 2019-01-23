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
    private List<Integer> res = new ArrayList<>();
    
    public List<Integer> inorderTraversal(TreeNode root) {
        // recursive solution
        // O(n) time, O(n) space
        if (root != null) {
            inorderTraversal(root.left);
            res.add(root.val);
            inorderTraversal(root.right);
        }
        return res;
    }
    
    //     public List<Integer> inorderTraversal(TreeNode root) {
    //         // iterative solution
    //         // O(n) time, O(n) space
    //         Stack<TreeNode> stack = new Stack<>();
    //         TreeNode curr = root;
        
    //         while (true) {
    //             while (curr != null) {
    //                 // go to the leftmost node
    //                 stack.push(curr);
    //                 curr = curr.left;
    //             }
            
    //             // exit if stack is empty
    //             if (stack.isEmpty()) break;
            
    //             // pop leftmost node, append and go right
    //             TreeNode leftmost = stack.pop();
    //             res.add(leftmost.val);
    //             curr = leftmost.right;

    //         }
    //         return res;
    //    }
    
}

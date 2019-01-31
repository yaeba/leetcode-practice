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
    public List<List<Integer>> levelOrder(TreeNode root) {
        // O(n) time, O(1) space
        
        // Using queue and BFS
        List<List<Integer>> res = new ArrayList<>();
        
        if (root == null) {
            return res;
        }
        
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        
        while (!queue.isEmpty()) {
            // process all nodes in current level
            List<Integer> temp = new ArrayList<>();
            int n_nodes = queue.size();
            for (int i=0; i<n_nodes; i++) {
                TreeNode current = queue.poll();
                temp.add(current.val);
                
                if (current.left != null) queue.offer(current.left);
                if (current.right != null) queue.offer(current.right);
            }
            
            res.add(temp);
        }
        
        return res;
    }
}

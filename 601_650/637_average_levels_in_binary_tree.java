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
    public List<Double> averageOfLevels(TreeNode root) {
        // use breadth-first search
        
        List<Double> res = new ArrayList<>();
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        
        while (!queue.isEmpty()) {
            long runningTotal = 0;
            long count = queue.size();
            
            // extract nodes in current level and sum
            for (long i=0; i<count; i++) {
                TreeNode curr = queue.poll();
                runningTotal += curr.val;
                
                // add any nodes for exploration
                if (curr.left != null) queue.offer(curr.left);
                if (curr.right != null) queue.offer(curr.right);
            }
            
            res.add(1.0 * runningTotal / count);
        }
        
        return res;
        
    }
}

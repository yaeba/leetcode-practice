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
    List<List<Integer>> res;
    
    private void traverseTree(TreeNode node, int level) {
        if (node == null) {
            return;
        } else if (res.size() == level) {
            // root not null, create space for another level
            res.add(new ArrayList<Integer>());
        }
        
        res.get(level).add(node.val);
        traverseTree(node.left, level + 1);
        traverseTree(node.right, level + 1);
    }
    
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        res = new ArrayList<>();
        
        // traverse normally, then reverse the result
        traverseTree(root, 0);
        Collections.reverse(res);
        return res;
    }
}

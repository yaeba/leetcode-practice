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
    private void pathSumDFS(TreeNode root, int sum, List<Integer> tmp,
			    List<List<Integer>> res) {
        if (root == null) {
            // reached end
            return;
        } 
        
        tmp.add(root.val);
        
        if (root.left == null && root.right == null
	    && sum == root.val) {
            // found a path with target sum (choose)
            res.add(new ArrayList<>(tmp));
        } else {
            // continue further (explore)
            pathSumDFS(root.left, sum - root.val, tmp, res);
            pathSumDFS(root.right, sum - root.val, tmp, res);
        }
        
        // remove (unchoose)
        tmp.remove(tmp.size() - 1);
    }
    
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        // backtracking
        List<List<Integer>> res = new ArrayList<>();
        pathSumDFS(root, sum, new ArrayList<Integer>(), res);
        return res;
    }
}

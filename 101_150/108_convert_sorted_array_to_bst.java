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
    public TreeNode createTreeR(int[] nums, int start, int end) {
        if (start > end) {
            // no more element to insert
            return null;
        }
        
        // create subtree holding middle element
        int mid = (start + end) / 2;
        TreeNode node = new TreeNode(nums[mid]);
        
        node.left = createTreeR(nums, start, mid - 1);
        node.right = createTreeR(nums, mid + 1, end);
        
        return node;
    }
    public TreeNode sortedArrayToBST(int[] nums) {
        return createTreeR(nums, 0, nums.length - 1);
    }
}

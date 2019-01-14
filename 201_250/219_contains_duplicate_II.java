class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        if (nums == null || nums.length <= 1) {
            return false;
        }
        
        // O(n) time, O(k) space
        HashSet<Integer> set = new HashSet<>();
        
        for (int i=0; i<nums.length; i++) {
            if (i > k) {
                // only need to preserve previous k+1 elements
                // in memory
                set.remove(nums[i-k-1]);
            }
            if (!set.add(nums[i])) {
                // found a number exists k+1 steps away
                return true;
            }
        }
        return false;
    }
}

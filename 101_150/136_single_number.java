class Solution {
    public int singleNumber(int[] nums) {
        // using XOR to find the unique number among pairs of duplicates
        
        if (nums.length == 1) {
            return nums[0];
        }
        
        for (int i=1; i<nums.length; i++) {
            nums[0] ^= nums[i];
        }
        return nums[0];
    }
}

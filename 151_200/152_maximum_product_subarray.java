class Solution {
    public int maxProduct(int[] nums) {
        if (nums == null || nums.length == 0) {
            return -1;
        }
        
        // similar to Kadane's algorithm, keep track of
        // both min and max since min may become max by
        // multiplying an negative number
        int currMin, currMax, maxProd;
        currMin = currMax = maxProd = nums[0];
        
        for (int i=1; i<nums.length; i++) {
            if (nums[i] < 0) {
                // swap min and max
                int tmp = currMin;
                currMin = currMax;
                currMax = tmp;
            }
            
            currMax = Math.max(nums[i], nums[i]*currMax);
            currMin = Math.min(nums[i], nums[i]*currMin);
            maxProd = Math.max(maxProd, currMax);
        }
        
        return maxProd;
    }
}

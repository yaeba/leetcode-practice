class Solution {
    public int recurSearch(int[] nums, int low, int high, int target) {
        if (low > high) {
            // not found
            return low;
        }
        int mid = (low + high) / 2;
        
        if (nums[mid] > target) {
            return recurSearch(nums, low, mid-1, target);
        } else if (nums[mid] < target) {
            return recurSearch(nums, mid+1, high, target);
        } else {
            // found
            return mid;
        }
    }
    
    public int searchInsert(int[] nums, int target) {
        return recurSearch(nums, 0, nums.length-1, target);
    }
}

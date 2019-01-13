class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] res = new int[]{-1, -1};
        
        if (nums == null || nums.length == 0) {
            return res;
        }
        
        // O(log n) time, O(1) space
        // using binary search based approach
        int firstPos = bSearch(nums, 0, nums.length-1, true, target);
        int lastPos = bSearch(nums, firstPos, nums.length-1, false, target);
        
        res[0] = firstPos;
        res[1] = lastPos;
        
        return res;
    }
    
    public int bSearch(int[] nums, int left, int right,
                      boolean searchFirst, int target) {
        if (left == -1) {
            // lower bound not found
            return -1;
        }
        
        int lastSeen = -1;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            
            if (nums[mid] == target) {
                // update last seen index
                lastSeen = mid;
            }
            
            if (target < nums[mid] || 
               (searchFirst && target == nums[mid])) {
                // search in the left half
                right = mid - 1;
            } else {
                // search in the right half
                left = mid + 1;
            }
        }
        
        // found the position or not exist within array
        return lastSeen;
    }
}

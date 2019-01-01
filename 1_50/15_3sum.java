class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        
        if (nums == null || nums.length < 3) {
            return res;
        }
        
        Arrays.sort(nums);
        
        for (int i=0; i<nums.length-2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                // dupes
                continue;
            }

            int target = -1 * nums[i];
            int j = i + 1;
            int k = nums.length - 1;
            
            if (target < 0 || nums[j] > target) {
                // no more possible answer
                break;
            }
            
            while (j < k) {
                int diff = target - nums[j] - nums[k];
                if (diff == 0) {
                    // found an answer
                    res.add(Arrays.asList(new Integer[]{nums[i], nums[j], nums[k]}));
                    
                    // skip dupes
                    while (j < k && nums[j] == nums[j+1]) j++;
                    while (j < k && nums[k] == nums[k-1]) k--;
                    j++;
                    k--;
                } else if (diff > 0) {
                    j++;
                } else {
                    k--;
                }
                
            }
        }
        return res;
    }
}

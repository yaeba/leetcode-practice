class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        // using backtracking
        
        List<List<Integer>> res = new ArrayList<>();
        
        subsetRecursive(nums, 0, new ArrayList<Integer>(), res);
        
        return res;
    }
    
    public void subsetRecursive(int[] nums, int start,
                               List<Integer> tmp,
                               List<List<Integer>> res) {
        if (start == nums.length) {
            // choose
            res.add(new ArrayList<>(tmp));
            return;
        }
        
        // without nums[start] (explore)
        subsetRecursive(nums, start+1, tmp, res);
        
        // with nums[start] (explore)
        tmp.add(nums[start]);
        subsetRecursive(nums, start+1, tmp, res);
        
        // backtrack (unchoose)
        tmp.remove(tmp.size() - 1);
        
    }
}

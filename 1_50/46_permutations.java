class Solution {
    public List<List<Integer>> permute(int[] nums) {
        // using backtracking
        List<List<Integer>> res = new ArrayList<>();
        permuteR(nums, new ArrayList<>(), res);
        return res;
    }
    
    public void permuteR(int[] nums,
                        List<Integer> tmp,
                        List<List<Integer>> res) {
        if (tmp.size() == nums.length) {
            // choose
            res.add(new ArrayList<>(tmp));
            return;
        }
        
        for (int i=0; i<nums.length; i++) {
            if (tmp.contains(nums[i])) {
                // skip
                continue;
            }
            
            // add this number and explore further
            tmp.add(nums[i]);
            permuteR(nums, tmp, res);
            
            // unchoose
            tmp.remove(tmp.size() - 1);
        }
    }
}

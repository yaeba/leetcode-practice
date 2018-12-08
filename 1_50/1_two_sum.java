import java.util.HashMap;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<>();
        
        for (int i=0; i<nums.length; i++){
            int comp = target - nums[i];
          
            if (!map.containsKey(comp)){
                map.put(nums[i], i);
            } else {
                return new int[]{map.get(comp), i};
            }
        }
        return null;
    }
}

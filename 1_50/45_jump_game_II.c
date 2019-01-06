int jump(int* nums, int numsSize) {
    if (nums == NULL || numsSize == 0) {
        return -1;
    } else if (numsSize == 1) {
        return 0;
    }
    
    // use idea similar to breadth-first search, explore
    // nodes that are reachable from this level
    // before advancing to next level
    int target = numsSize - 1;
    int minStep = 0;
    int nextLevel = 0;
    int maxJump = 0;
    
    for (int i=0; i<=target; i++) {
        int jump = nums[i] + i;
        if (jump >= target) {
            // target is reachable from here
            return minStep + 1;
        }
        
        // update the furthest jump from this level
        maxJump = jump > maxJump ? jump : maxJump;
        
        if (i == nextLevel) {
            // advance to next level
            minStep++;
            nextLevel = maxJump;
        }
    }
    
    return -1;
}

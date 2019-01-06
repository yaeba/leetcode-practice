bool canJump(int* nums, int numsSize) {
    // go from right to left, determine if each position
    // can reach last position, if yes, it is sufficient to just
    // be able to reach this position
    
    if (numsSize == 1) {
        return true;
    } else if (nums[0] == 0) {
        return false;
    }
    
    int lastReachable = numsSize - 1;
    
    for (int i=lastReachable-1; i>=0; i--) {
        if (i + nums[i] >= lastReachable) {
            // it is enough to just reach at this index
            lastReachable = i;
        }
    }
    
    return lastReachable == 0;
}

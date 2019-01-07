int firstMissingPositive(int* nums, int numsSize) {
    // first missing positive can only be in range
    // [1, numsSize + 1]
    
    // filter by setting not possible element to INT_MAX
    for (int i=0; i<numsSize; i++) {
        if (nums[i] <= 0 || nums[i] > numsSize) {
            nums[i] = INT_MAX;
        }
    }
    
    // for the rest elements, use abs(elem)-1 as index to store
    // presence
    for (int i=0; i<numsSize; i++) {
        int idx = abs(nums[i]) - 1;
        if (abs(nums[i]) != INT_MAX && nums[idx] > 0) {
            // set to -nums[idx] to indicate presence
            nums[idx] = -1 * nums[idx];
        }
    }
    
    // find the first non-negative index
    for (int i=0; i<numsSize; i++) {
        if (nums[i] > 0) {
            return i + 1;
        }
    }
    
    return numsSize + 1;
}

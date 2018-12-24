int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0 || numsSize == 1) {
        return numsSize;
    }
    
    int j = 0;
    
    for (int i=1; i<numsSize; i++) {
        if (nums[i] == nums[j]) {
            continue;
        }
        nums[++j] = nums[i];
    }
    
    return j + 1;
}

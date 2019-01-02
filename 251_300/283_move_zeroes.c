void moveZeroes(int* nums, int numsSize) {
    int idx = 0;
    
    for (int i=0; i<numsSize; i++) {
        int val = nums[i];
        if (val != 0) {
            nums[idx++] = val;
        }
    }
    
    for (; idx<numsSize; idx++) {
        nums[idx] = 0;
    }
}

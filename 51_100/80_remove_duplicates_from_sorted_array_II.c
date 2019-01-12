int removeDuplicates(int* nums, int numsSize) {
    if (nums == NULL || numsSize == 0) {
        return 0;
    }
    
    // O(n) time, O(1) space
    
    // use two pointers to modify array in-place
    int i, j;
    int maxOccur = 2;
    int prev = nums[0];
    int count = 1;
    
    for (i=1, j=1; j<numsSize; j++) {
        if (nums[j] == prev) {
            count++;
        } else {
            count = 1;
            prev = nums[j];
        }
        
        if (count <= maxOccur) {
            // modify array
            nums[i++] = nums[j];
        }
    }
    
    return i;
}

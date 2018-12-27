void reverseArray(int *nums, int left, int right) {
    if (left == right) {
        return;
    }
    
    int tmp;
    while (left < right) {
        tmp = nums[left];
        nums[left++] = nums[right];
        nums[right--] = tmp;
    }
}

void rotate(int* nums, int numsSize, int k) {
    
    k = k % numsSize;
    
    // reverse whole array
    reverseArray(nums, 0, numsSize-1);
    // reverse first part
    reverseArray(nums, 0, k-1);
    // reverse last part
    reverseArray(nums, k, numsSize-1);
}

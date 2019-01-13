void swap(int *nums, int a, int b) {
    int temp = nums[a];
    nums[a] = nums[b];
    nums[b] = temp;
}

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

void nextPermutation(int* nums, int numsSize) {
    if (nums == NULL || numsSize <= 1) {
        return;
    }
    
    // O(n) time, O(1) space
    
    // from right to left, find first decreasing number
    int i = numsSize - 1;
    while (i >= 0 && nums[i-1] >= nums[i]) i--;
    i--;
    
    // swap it with first number greater than it in tail
    if (i >= 0) {
        int j = numsSize - 1;
        while (j > i && nums[j] <= nums[i]) j--;
        swap(nums, i, j);
    }
    
    // reverse the remaining numbers
    reverseArray(nums, i + 1, numsSize - 1);
}

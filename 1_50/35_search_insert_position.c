int searchInsert(int* nums, int numsSize, int target) {
    // use binary search
    int l = 0, r = numsSize - 1;
    int mid;
    
    while (l <= r) {
        mid = (l + r) / 2;
        if (nums[mid] > target) {
            r = mid - 1;
        } else if (nums[mid] < target) {
            l = mid + 1;
        } else {
            // found
            return mid;
        }
    }
    return l;
}

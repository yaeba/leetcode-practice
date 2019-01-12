// int findPeakElement(int* nums, int numsSize) {
//     // linear search, O(n) time, O(1) space
//     for (int i=0; i<numsSize; i++) {
//         if (nums[i] > nums[i+1]) {
//             return i;
//         }
//     }
//     return numsSize - 1;
// }

int findPeakElement(int* nums, int numsSize) {
    // binary search based, O(log n) time, O(1) space
    
    if (nums == NULL || numsSize == 0) {
        return -1;
    } else if (numsSize == 1) {
        return 0;
    }
    
    int left = 0, right = numsSize - 1;
    while (left < right) {
        // use binary search
        int mid = (left + right) / 2;
        int val = nums[mid];
        
        if (val > nums[mid+1]) {
            // negative slope, answer in [left, mid]
            right = mid;
        } else {
            // answer in [mid+1, right]
            left = mid + 1;
        }
    }
    // search space left with 1 element
    return left;
}

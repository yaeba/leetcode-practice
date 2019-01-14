int minSubArrayLen(int s, int* nums, int numsSize) {
    if (nums == NULL || numsSize == 0) {
        return 0;
    } else if (nums[0] >= s) {
        return 1;
    }
    
    // O(n) time, O(1) space
    
    int minLength = INT_MAX;
    int head = 0;
    int sum = nums[head];
    int length = 1;
    
    for (int tail=1; tail<numsSize; tail++) {
        sum += nums[tail];
        length++;
        
        while (sum >= s) {
            // update minLength
            minLength = length < minLength ? length : minLength;
            
            // can safely remove the head element
            sum -= nums[head++];
            length--;
        }
    }
    
    return minLength < INT_MAX ? minLength : 0;
}

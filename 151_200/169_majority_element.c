int majorityElement(int* nums, int numsSize) {
    int minSize = numsSize % 2 ? (numsSize/2)+1 : numsSize/2;
    
    while (true) {
        int r = rand() % numsSize;
        int major = nums[r];
        int count = 0;
        
        for (int i=0; i<numsSize; i++) {
            if (nums[i] == major) count++;
            if (count >= minSize) return major;
        }
    }
}

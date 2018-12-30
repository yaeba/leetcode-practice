int cmp(const void *a, const void *b) {
    return (*(int*)a) - (*(int*)b);
}


int threeSumClosest(int* nums, int numsSize, int target) {
    if (numsSize == 3) {
        return nums[0] + nums[1] + nums[2];
    }
    
    int minDiff = INT_MAX;
    
    qsort(nums, numsSize, sizeof(int), cmp);
    
    for (int i=0; i<numsSize-2; i++) {
        if (i > 0 && nums[i] == nums[i-1]) {
            // dupes
            continue;
        }
        
        int j = i + 1;
        int k = numsSize - 1;
        
        while (j < k) {
            int diff = target - nums[i] - nums[j] - nums[k];
            
            if (diff == 0) {
                // found exact three sum
                return target;
            }
            
            // update minimum difference
            minDiff = abs(diff) < abs(minDiff) ? diff : minDiff;
            
            if (diff > 0) {
                // get closer by adding larger number
                j++;
            } else {
                // get closer by adding smaller number
                k--;
            }
        }
    }
    return target - minDiff;
}

void merge(int* nums1, int m, int* nums2, int n) {
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;
    
    while (k >= 0 && j >= 0) {
        if (i < 0) {
            // copy the rest from second array
            nums1[k--] = nums2[j--];
        } else {
            if (nums1[i] > nums2[j]) {
                // copy from first array
                nums1[k--] = nums1[i--];
            } else {
                // copy from second array
                nums1[k--] = nums2[j--];
            }
        }
    }
}

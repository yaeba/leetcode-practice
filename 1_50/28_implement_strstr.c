int strStr(char* haystack, char* needle) {
    int len_needle = strlen(needle);
    int len_haystack = strlen(haystack);
    
    if (len_needle == 0) {
        return 0;
    }
    
    for (int i=0; i<=len_haystack-len_needle; i++) {
        int j;
        for (j=0; j<len_needle; j++) {
            if (haystack[i+j] != needle[j]) {
                break;
            }
        }
        if (j == len_needle) {
            // found the occurence of needle at i
            return i;
        }
    }
    // not found
    return -1;
}

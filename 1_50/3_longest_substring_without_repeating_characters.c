int lengthOfLongestSubstring(char* s) {
    int i, longestLen, size;
    
    // save index of the characters occur
    int address[128] = {0};
    
    i = longestLen = size = 0;
    
    // find len of string
    while (s[size] != '\0') {
        size++;
    }
    
    for (int j=0; j<size; j++) {
        i = address[s[j]] > i ? address[s[j]] : i;
        longestLen = longestLen > j - i + 1 ? longestLen : j - i + 1;
        address[s[j]] = j + 1;
    }
    return longestLen;
}

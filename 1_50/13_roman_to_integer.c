int romanToInt(char* s) {
    int res = 0;
    char *p = s;
    
    if (!p) {
        return 0;
    }
    
    while(*p) {
        switch(*p) {
            case 'I':
                res += (*(p+1) == 'V' || *(p+1) == 'X') ?
                        -1 : 1;
                break;
            case 'V':
                res += 5;
                break;
            case 'X':
                res += (*(p+1) == 'L' || *(p+1) == 'C') ?
                        -10: 10;
                break;
            case 'L':
                res += 50;
                break;
            case 'C':
                res += (*(p+1) == 'D' || *(p+1) == 'M') ?
                        -100 : 100;
                break;
            case 'D':
                res += 500;
                break;
            case 'M':
                res += 1000;
                break;
        }
        p++;
    }
    return res;
}

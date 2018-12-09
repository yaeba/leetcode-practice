int reverse(int x) {
    long long reverse = 0;
    int sign = x >= 0 ? 1 : -1;
    x = abs(x);
    while (x != 0){
        reverse = reverse * 10 + x % 10;
        x /= 10;
    }
    return ((reverse > INT_MAX) || (reverse < INT_MIN))? 0 : reverse*sign;
}

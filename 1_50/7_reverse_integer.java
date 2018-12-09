class Solution {
    public int reverse(int x) {
        int sign = x > 0 ? 1 : -1;
        x = x > 0 ? x : -x;
        long rev = 0;
            
        while (x != 0) {
            rev = rev * 10 + (long) x % 10;
            
            // check if reversed overflows
            if (rev != (int) rev) {
                return 0;
            }
            
            x /= 10;
        }
        return (int) rev * sign;
    }
}

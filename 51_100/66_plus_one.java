class Solution {
    public int[] plusOne(int[] digits) {
        if (digits == null) {
            return null;
        }
        
        for (int i=digits.length-1; i>=0; i--) {
            if (digits[i] < 9) {
                // no carry over, return answer
                digits[i]++;
                return digits;
            } else {
                // carry over and repeat
                digits[i] = 0;
            }
        }
        
        // all digits were 9s
        int[] newDigits = new int[digits.length + 1];
        newDigits[0] = 1;
        
        return newDigits;
    }
}

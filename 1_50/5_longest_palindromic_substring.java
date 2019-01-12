class Solution {
    public String longestPalindrome(String s) {
        if (s == null || s.length() <= 1) {
            return s;
        }
        
        // O(n^2) time, O(1) space
        // we can expand and find longest palindrome from
        // 2n-1 centers
        int maxLength = -1;
        int start = 0;
        
        for (int i=0; i<s.length(); i++) {
            int currLength = Math.max(
                        expandMid(s, i, i), expandMid(s, i, i+1));
            if (currLength > maxLength) {
                // update global longest and start
                maxLength = currLength;
                start = i - (currLength - 1) / 2;
            }
        }
        
        return s.substring(start, start + maxLength);
    }
    
    public int expandMid(String s, int start, int end) {
        while (start >= 0 && end < s.length()
              && s.charAt(start) == s.charAt(end)) {
            // expand towards both ends
            start--;
            end++;
        }
        return (end - 1) - (start + 1) + 1;
    }
}

// public class Solution{
// 	// Manacher algortihm - O(n) time, O(1) space
//     int len = 0, maxLength = 0, init = 0;
//     public String longestPalindrome(String s) {
//         char[] chars = s.toCharArray();
//         len = s.length();
//         if (len <= 1) return s;
//         for (int i = 0; i < len; i++) {
//             i = manacher(chars, i);
//         }
//         return s.substring(init, init + maxLength);
//     }
//     private int manacher(char[] chars, int k) {
//         int i = k - 1, j = k;
//         while (j < len - 1 && chars[j] == chars[j + 1]) j++;
//         int nextCenter = j++;
//         while (i >= 0 && j < len && chars[i] == chars[j]) {
//             i--;
//             j++;
//         }
//         if (j - i - 1 > maxLength) {
//             maxLength = j - i - 1;
//             init = i + 1;
//         }
//         return nextCenter;
//     }
// }

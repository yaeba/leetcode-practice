class Solution {
    public int lengthOfLastWord(String s) {
        int len = 0;
        boolean isChar = false;
        
        // scan from last word
        for (int i=s.length()-1; i>=0; i--) {
            if (Character.isLetter(s.charAt(i))) {
                isChar = true;
                len++;
            } else if (isChar) {
                // encounter whitespace left of last word
                return len;
            }
            // skip any other characters otherwise
        }
        return len;
    }
}

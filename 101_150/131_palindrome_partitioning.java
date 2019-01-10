class Solution {
    public boolean isPalindrome(String s) {
        // check if a string is a palindrome
        int n = s.length();
        for (int i=0; i<(n/2); i++) {
            if (s.charAt(i) != s.charAt(n-1-i)) {
                return false;
            }
        }
        return true;
    }
    
    public void partitionR(String s, List<String> tmp,
                      List<List<String>> res) {
        if (s.length() == 0) {
            // base case, reach leaf (choose)
            res.add(new ArrayList<>(tmp));
            return;
        }
        
        for (int i=1; i<=s.length(); i++) {
            String candidate = s.substring(0, i);
            
            if (isPalindrome(candidate)) {
                // it is palindrome, add to tmp and explore
                tmp.add(candidate);
                partitionR(s.substring(i, s.length()), tmp, res);
                
                // remove from tmp (unchoose)
                tmp.remove(tmp.size() - 1);
            }
        }
    }
    
    public List<List<String>> partition(String s) {
        // using backtracking (or dfs)
        List<List<String>> res = new ArrayList<>();
        
        if (s == null || s.length() == 0) {
            return res;
        }
        
        partitionR(s, new ArrayList<String>(), res);
        
        return res;
    }
}

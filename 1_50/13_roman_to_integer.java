import java.util.HashMap;

class Solution {
    public int romanToInt(String s) {
        if (s == "") {
            return 0;
        }
        
        HashMap<Character, Integer> map = new HashMap<Character, Integer>()
        {{
            put('I', 1);
            put('V', 5);
            put('X', 10);
            put('L', 50);
            put('C', 100);
            put('D', 500);
            put('M', 1000);
        }};
        
        int res = map.get(s.charAt(0));
        
        // 'I' can be placed before V and X to make 4 and 9
        // check if subsequent roman is greater than previous
        
        for (int i=1; i<s.length(); i++) {
            if (map.get(s.charAt(i)) > map.get(s.charAt(i-1))) {
                // substract twice the added previous number
                res -= 2 * map.get(s.charAt(i-1)); 
            }
            res += map.get(s.charAt(i));
        }
        
        return res;

    }
}

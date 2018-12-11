class Solution:
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        if s == "":
            return 0
        
        d = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100,
            'D': 500, 'M': 1000}
        
        res = d[s[0]]
        
        # 'I' can be placed before V and X to make 4 and 9
        # check if subsequent roman is greater than previous
        
        for i in range(1, len(s)):
            if d[s[i]] > d[s[i-1]]:
                # substract twice the added previous number
                res -= 2 * d[s[i-1]]
            res += d[s[i]]
        
        return res
    

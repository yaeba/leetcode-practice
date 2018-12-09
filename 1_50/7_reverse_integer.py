
class Solution:
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        rev = ""
        if x >= 0:
            rev = int(str(x)[::-1])
        else:
            rev = int(str(x)[:0:-1]) * -1
        
        # check if reversed overflows
        return rev if abs(rev) < 2 ** 31 else 0

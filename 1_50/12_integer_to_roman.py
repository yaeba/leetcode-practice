class Solution:
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        nums = [(1000, 'M'), (900, 'CM'), (500, 'D'), (400, 'CD'), (100, 'C'),
               (90, 'XC'), (50, 'L'), (40, 'XL'), (10, 'X'), (9, 'IX'),
               (5, 'V'), (4, 'IV'), (1, 'I')]
        roman = ""
        
        # % operator is slow
        while num != 0:
            for (n, c) in nums:
                while num >= n:
                    roman += c
                    num -= n

        return roman

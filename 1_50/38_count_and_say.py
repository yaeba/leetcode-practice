import itertools

class Solution:
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        res = "1"
        # using itertools groupby
        for _ in range(n - 1):
            res = ''.join(["{}{}".format(len(list(group)), digit)
                          for (digit, group) in itertools.groupby(res)])
        
        return res

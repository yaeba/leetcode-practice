class Solution:
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = [[]]
        
        for n in nums:
            res += [lst + [n] for lst in res]
        
        return res
    

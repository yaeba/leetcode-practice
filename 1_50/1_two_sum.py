class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        num = dict()
        for idx, val in enumerate(nums):
            comp = target - val
            if comp not in num:
                # not yet seen the complement
                num[val] = idx
            else:
                return [num[comp], idx]
        return None
    

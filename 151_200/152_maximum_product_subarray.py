class Solution:
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # maximum contiguous product is reachable from either start
        # or end or both
        numsRev = nums[::-1]
        
        for i in range(1, len(nums)):
            nums[i] *= nums[i-1] or 1
            numsRev[i] *= numsRev[i-1] or 1
            
        return max(nums + numsRev)

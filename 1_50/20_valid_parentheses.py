class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        
        close = {')': '(', '}': '{', ']': '['}
        stack = list()
        
        for brac in s:
            if brac not in close:
                # open bracket
                stack.append(brac)
            else:
                # close bracket
                if not len(stack):
                    return False
                if close[brac] != stack.pop():
                    return False
        
        # check if stack still contains open brackets
        return not len(stack)
    

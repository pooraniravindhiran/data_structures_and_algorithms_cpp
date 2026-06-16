# TC- O(n)
# SC- O(n)

class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        
        # goal is to move smaller elements as fas as possible to the left
        stack = [] # monotonically inc

        for ch in num:
            digit = int(ch)
            while k and stack and digit<int(stack[-1]):
                stack.pop()
                k -= 1
            stack.append(ch)
        
        if k:
            stack = stack[:-k] # if k elements weren't removed yet, then remove elements from tail
        
        return "".join(stack).lstrip('0') or "0" # remove leading 0s

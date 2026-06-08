# TC- O(n)
# SC- O(n)

class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        
        # monotonic stack of decreasing temperatures. once you get a warmer temperature, pop and update all. 
        # WHAT HAPPENS IN THE END?
        # WHY STACK PATTERN?

        stack = []
        n = len(temperatures)
        ans = [0]*n

        for i in range(n):
            curr_temp = temperatures[i]
            
            while(stack and curr_temp>temperatures[stack[-1]]):
                ans[stack[-1]] = i-stack[-1]
                stack.pop()
            stack.append(i)
        
        return ans

        
# TC- O(n)
# SC- O(n)

class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]: 
        stack = []
        ans = [0]*len(temperatures)

        for day, temp in enumerate(temperatures):
            while(stack and temp>temperatures[stack[-1]]):
                cooler_day = stack.pop()
                ans[cooler_day]= day-cooler_day
            stack.append(day)

        return ans
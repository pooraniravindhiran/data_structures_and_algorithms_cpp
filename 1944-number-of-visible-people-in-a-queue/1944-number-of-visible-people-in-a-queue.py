class Solution:
    def canSeePersonsCount(self, heights: List[int]) -> List[int]:
        
        ans = [0]*len(heights)
        stack = []

        for i in range(len(heights)-1, -1, -1):
            curr_ht = heights[i]
            while stack and curr_ht >= heights[stack[-1]]:
                stack.pop()
                ans[i] += 1
            if stack:
                ans[i]+=1
            stack.append(i)
        return ans

        
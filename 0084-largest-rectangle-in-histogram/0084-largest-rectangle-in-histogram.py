# TC- O(n)
# SC- O(n)

class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = []
        max_area = 0
        heights.append(0) # to push out elements in stack at the end

        for idx, ht in enumerate(heights):
            while stack and ht<heights[stack[-1]]:
                height = heights[stack.pop()]
                rb = idx-1
                lb = 0 if not stack else stack[-1]+1
                width = rb-lb+1
                max_area = max(max_area, height*width)
                
            stack.append(idx)
        return max_area
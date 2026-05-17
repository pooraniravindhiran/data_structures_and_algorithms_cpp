# TC- O(n)
# SC- O(n)

class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        max_area = 0
        stack = [] # store indices 
        heights.append(0) # to flush out stack

        for idx, ht in enumerate(heights):
            while stack and ht<heights[stack[-1]]:
                popped_idx = stack.pop()
                height = heights[popped_idx]
                left_smaller = stack[-1] if stack else -1
                width = idx - left_smaller -1 
                area = height*width
                max_area = max(area, max_area)
            stack.append(idx)

        return max_area
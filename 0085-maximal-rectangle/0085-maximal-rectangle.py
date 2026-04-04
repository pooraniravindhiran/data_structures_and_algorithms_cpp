# TC- O(mn)
# SC- O(n)

class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        rows, cols = len(matrix), len(matrix[0])
        heights = [0]*cols
        max_area = 0

        for row in matrix:

            # create rows that represent heights
            for c in range(cols):
                if row[c]=='0':
                    heights[c] = 0
                else:
                    heights[c] += 1
            
            # use a monotonic stack to keep indices of bars with increasing order
            # example for row3- 3 1 3 2 2 
            stack = [-1] 
            for c in range(cols):
                while stack[-1]!=-1 and heights[c]<heights[stack[-1]]:
                    h = heights[stack.pop()]
                    w = c-1-stack[-1]
                    max_area = max(max_area, w*h)
                stack.append(c)

            while(stack[-1]!=-1):
                h = heights[stack.pop()]
                w = cols-1-stack[-1]
                max_area = max(max_area, w*h)

        return max_area

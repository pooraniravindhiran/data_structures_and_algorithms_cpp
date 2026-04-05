# TC- O(mn)
# SC- O(n)

class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        # for every row, you compute height add 1 if 1, else reset to 0
        # area is width*height. width here would be whenever height decreases
        rows, cols = len(matrix), len(matrix[0])
        heights = [0]*(cols+1)
        maxarea = 0

        for row in matrix:
            
            # compute heights for this row
            for idx, col in enumerate(row):
                if col=="1":
                    heights[idx]+=1
                else:
                    heights[idx] = 0
            
            stack = []
            # compute largest area for this row
            for idx, ht in enumerate(heights):
                while stack and ht<heights[stack[-1]]:
                    height = heights[stack.pop()]
                    rb = idx-1
                    lb = 0 if not stack else stack[-1]+1
                    width = rb-lb+1
                    maxarea=max(maxarea, width*height)
                stack.append(idx)
        return maxarea

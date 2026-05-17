# TC- O(mn)
# SC- O(n)

class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        rows = len(matrix)
        cols = len(matrix[0])
        heights = [0]*(cols+1)
        max_area = 0

        for i in range(rows):
            # compute ht
            for j in range(cols):
                if matrix[i][j]=='1':
                    heights[j] += 1
                else:
                    heights[j] = 0

            stack = []

            # compute area for this row
            for j, ht in enumerate(heights):
                
                # pop greater hts from stack
                while stack and ht<stack[-1][0]:
                    popped_ht, _ = stack.pop()
                    height = popped_ht
                    left_smaller = stack[-1][1] if stack else -1
                    width = j - left_smaller -1
                    area = height*width
                    max_area = max(area, max_area)

                # append to stack
                stack.append((ht, j))

        return max_area
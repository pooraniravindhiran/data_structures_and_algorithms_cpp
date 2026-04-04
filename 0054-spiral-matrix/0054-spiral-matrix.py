# TC- O(mn)
# SC- O(1)

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        rows, cols = len(matrix), len(matrix[0])
        ans = []

        left, right, top, bottom = 0, cols-1, 0, rows-1
        while(len(ans)!=(rows*cols)):
            for c in range(left, right+1):
                ans.append(matrix[top][c])
            top += 1

            for r in range(top, bottom+1):
                ans.append(matrix[r][right])
            right -= 1

            if top<= bottom:
                for c in range(right, left-1, -1):
                    ans.append(matrix[bottom][c])
                bottom -= 1
            
            if left <= right:
                for r in range(bottom, top-1, -1):
                    ans.append(matrix[r][left])
                left += 1

        return ans
# TC- O(m+n)
# SC- O(1)

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        rows, cols = len(matrix), len(matrix[0])

        r, c = 0, cols-1
        while(r<rows and r>=0 and c<cols and c>=0):
            if target==matrix[r][c]:
                return True
            elif target<matrix[r][c]:
                c = c-1
            elif target>matrix[r][c]:
                r = r+1
        return False
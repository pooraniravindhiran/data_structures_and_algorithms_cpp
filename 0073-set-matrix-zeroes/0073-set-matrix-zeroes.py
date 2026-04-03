# TC- O(mn)
# SC- O(1)

class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        rows = len(matrix)
        cols = len(matrix[0])
        first_row = any(matrix[0][c]==0 for c in range(cols))
        first_col = any(matrix[r][0]==0 for r in range(rows))

        # mark
        for r in range(1, rows):
            for c in range(1, cols):
                if matrix[r][c]==0:
                    matrix[0][c] = 0
                    matrix[r][0] = 0
        
        # zero based on marks
        for r in range(1, rows):
            for c in range(1, cols):
                if matrix[r][0]==0 or matrix[0][c]==0:
                    matrix[r][c] = 0

        # first row
        if first_row:
            for c in range(cols):
                matrix[0][c] = 0

        # first col
        if first_col:
            for r in range(rows):
                matrix[r][0] = 0
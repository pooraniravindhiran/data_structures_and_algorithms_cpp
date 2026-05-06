# TC- O(mn)
# SC- O(1)

class Solution:
    def largestSubmatrix(self, matrix: List[List[int]]) -> int:
        rows = len(matrix)
        cols = len(matrix[0])

        # compute heights 
        for r in range(1, rows):
            for c in range(cols):
                if matrix[r][c]==1:
                    matrix[r][c] += matrix[r-1][c]
        
        max_area = 0
        # since cols are exchangeable, to find largest submatrix, let's sort heights in descending order for each row
        for r in range(rows):
            current_row = sorted(matrix[r], reverse=True)

            for i in range(cols):
                height = current_row[i]
                width = i+1
                max_area = max(max_area, height*width)
        return max_area


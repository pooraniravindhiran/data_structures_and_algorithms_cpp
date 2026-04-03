class Solution:

    def transpose(self, matrix) -> None:
        for r in range(self.n):
            for c in range(r+1, self.n):
                if(r!=c):
                    matrix[r][c], matrix[c][r] = matrix[c][r], matrix[r][c]

    def reflect(self, matrix) -> None:
        for row in matrix:
            row.reverse()

    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        self.n = len(matrix)
        self.transpose(matrix)
        self.reflect(matrix)
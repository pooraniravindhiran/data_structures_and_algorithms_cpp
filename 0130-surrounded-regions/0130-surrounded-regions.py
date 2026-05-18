# TC- O(mn)
# SC- O(mn)

class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        rows, cols = len(board), len(board[0])

        def dfs(r, c):
            board[r][c] = "I"
            dirs = [-1, 0, 1, 0, -1]

            for d in range(len(dirs)-1):
                next_r = r+dirs[d]
                next_c = c+dirs[d+1]
                if 0<=next_r<rows and 0<=next_c<cols and board[next_r][next_c]=="O":
                    dfs(next_r, next_c)

        for i in range(cols):
            if board[0][i]=="O":
                dfs(0, i)
        for i in range(cols):
            if board[rows-1][i]=="O":
                dfs(rows-1, i)
        for i in range(rows):
            if board[i][0]=="O":
                dfs(i, 0)
        for i in range(rows):
            if board[i][cols-1]=="O":
                dfs(i, cols-1)
        
        for i in range(rows):
            for j in range(cols):
                if board[i][j]=="O":
                    board[i][j] = "X"
                elif board[i][j]=="I":
                    board[i][j] = "O"
        
# TC- O(mn)
# SC- O(mn)

class Solution:
    def dfs(self, grid, r, c, rows, cols):
        grid[r][c] = "0"
        dirs = [-1, 0, 1, 0, -1]
        for d in range(len(dirs)-1):
            next_r = r + dirs[d]
            next_c = c + dirs[d+1]

            if(next_r>=0 and next_r<rows and next_c>=0 and next_c<cols and grid[next_r][next_c]=="1"):
                self.dfs(grid, next_r, next_c, rows, cols)

    def numIslands(self, grid: List[List[str]]) -> int:
        ans = 0
        rows, cols = len(grid), len(grid[0])

        for r in range(rows):
            for c in range(cols):
                if grid[r][c]=="1":
                    ans += 1
                    self.dfs(grid, r, c, rows, cols)

        return ans
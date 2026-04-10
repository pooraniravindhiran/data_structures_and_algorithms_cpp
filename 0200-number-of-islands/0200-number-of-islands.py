# TC- O(mn)
# SC- O(mn)

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        ans = 0
        rows, cols = len(grid), len(grid[0])

        def dfs(r, c):
            grid[r][c] = '0'
            dirs = [-1, 0, 1, 0, -1]
            for d in range(len(dirs)-1):
                next_r = r+dirs[d]
                next_c = c+dirs[d+1]
                if(next_r>=0 and next_c>=0 and next_r<rows and next_c<cols and grid[next_r][next_c]=='1'):
                    dfs(next_r, next_c)

        for r in range(rows):
            for c in range(cols):
                if grid[r][c]=='1':
                    ans += 1
                    dfs(r, c)
        
        return ans
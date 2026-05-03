# TC- O(mn)
# SC- O(mn)

class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        max_area = 0
        def dfs(r, c):
            grid[r][c] = 0
            area = 1
            dirs = [-1, 0, 1, 0, -1]
            for d in range(len(dirs)-1):
                next_r = r+dirs[d]
                next_c = c+dirs[d+1]
                if next_r>=0 and next_r<len(grid) and next_c>=0 and next_c<len(grid[0]) and grid[next_r][next_c]==1:
                    area += dfs(next_r, next_c)
            return area
                    
        for r in range(len(grid)):
            for c in range(len(grid[0])):
                if grid[r][c]==1:
                    max_area = max(max_area, dfs(r, c))

        return max_area
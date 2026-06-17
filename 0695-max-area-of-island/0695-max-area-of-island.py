# TC- O(mn)
# SC- O(mn)

class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])

        dirs = [-1, 0, 1, 0, -1]

        def dfs(r, c):
            grid[r][c] = 0
            area = 1

            for d in range(len(dirs)-1):
                next_r, next_c = r+dirs[d], c+dirs[d+1]
                if 0<=next_r<m and 0<=next_c<n and grid[next_r][next_c]==1:
                    area += dfs(next_r, next_c)
            return area

        max_area = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j]==1:
                    area = dfs(i, j)
                    max_area = max(max_area, area)
        return max_area


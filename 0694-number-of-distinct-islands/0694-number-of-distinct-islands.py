# TC- O(mn)
# SC- O(mn)

class Solution:
    def dfs(self, grid, curr, base, total, shape):
        r, c = curr
        br, bc = base
        rows, cols = total
        dirs = [-1, 0, 1, 0, -1]

        grid[r][c] = 0
        shape.append((r-br, c-bc))

        for d in range(len(dirs)-1):
            next_r = r+dirs[d]
            next_c = c+dirs[d+1]

            if(next_r>=0 and next_c>=0 and next_r<rows and next_c<cols and grid[next_r][next_c]==1):
                self.dfs(grid, (next_r, next_c), (br,bc), (rows, cols), shape)

    def numDistinctIslands(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        shapes = set()

        for r in range(rows):
            for c in range(cols):
                if grid[r][c]==1:
                    shape = []
                    self.dfs(grid, (r,c), (r,c), (rows, cols), shape)
                    shapes.add(tuple(shape))

        return len(shapes)
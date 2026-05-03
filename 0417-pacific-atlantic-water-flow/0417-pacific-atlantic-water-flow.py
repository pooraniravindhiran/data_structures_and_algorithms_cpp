# TC- O(mn)
# SC- O(mn)

class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        rows, cols = len(heights), len(heights[0])

        pacific = set()
        atlantic = set()

        def dfs(r, c, visited):
            visited.add((r, c))

            dirs = [-1, 0, 1, 0, -1]
            for d in range(len(dirs)-1):
                nr, nc = r + dirs[d], c + dirs[d+1]

                if (
                    0 <= nr < rows and
                    0 <= nc < cols and
                    (nr, nc) not in visited and
                    heights[nr][nc] >= heights[r][c]   # reverse flow condition
                ):
                    dfs(nr, nc, visited)

        # Pacific: top row + left column
        for c in range(cols):
            dfs(0, c, pacific)
        for r in range(rows):
            dfs(r, 0, pacific)

        # Atlantic: bottom row + right column
        for c in range(cols):
            dfs(rows - 1, c, atlantic)
        for r in range(rows):
            dfs(r, cols - 1, atlantic)

        # intersection
        return list(pacific & atlantic)      
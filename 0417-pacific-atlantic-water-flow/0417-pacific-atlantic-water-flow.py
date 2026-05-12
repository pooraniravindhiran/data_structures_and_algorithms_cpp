# TC- O(mn)
# SC- O(mn)

class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        # let's identify cells from which rain flows into Pacific and add them into a set
        # let's identify cells from which rain flows into Atlantic and add them into a set
        # finally, let's find their intersection
        # it's easier to traverse from the ocean to cells than otherway round

        to_pacific_cells = set()
        to_atlantic_cells = set()
        
        rows = len(heights)
        cols = len(heights[0])
        dirs = [-1, 0, 1, 0, -1]

        def dfs(i, j, visited):
            if (i,j) in visited:
                return

            visited.add((i, j))
            for d in range(len(dirs)-1):
                next_i = i+dirs[d]
                next_j = j+dirs[d+1]
                if 0<=next_i<rows and 0<=next_j<cols and (next_i, next_j) not in visited and heights[next_i][next_j]>=heights[i][j]:
                    dfs(next_i, next_j, visited)

        # find ones to pacific
        for i in range(cols):
            dfs(0, i, to_pacific_cells)
        for i in range(rows):
            dfs(i, 0, to_pacific_cells)

        # find ones to atlantic
        for i in range(cols):
            dfs(rows-1, i, to_atlantic_cells)
        for i in range(rows):
            dfs(i, cols-1, to_atlantic_cells)

        to_both_cells = to_pacific_cells & to_atlantic_cells
        # print(to_both_cells)

        ans = []
        for (i,j) in to_both_cells:
            ans.append([i, j])
        return ans
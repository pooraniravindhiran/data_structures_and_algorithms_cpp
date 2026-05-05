# TC- O(mn)
# SC- O(1)

class Solution:
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0])

        def isMagic(i, j):
            s = set()
            for x in range(3):
                for y in range(3):
                    val = grid[i+x][j+y]
                    if val in s or val<1 or val>9:
                        return False
                    s.add(val)
        
            # check col sum
            for c in range(j, j+3):
                if grid[i][c]+grid[i+1][c]+grid[i+2][c]!=15:
                    return False

            # check row sum
            for r in range(i, i+3):
                if grid[r][j]+grid[r][j+1]+grid[r][j+2]!=15:
                    return False

            # check diag sum
            main_diag_sum = grid[i][j]+grid[i+1][j+1]+ grid[i+2][j+2]
            off_diag_sum = grid[i][j+2]+grid[i+1][j+1]+ grid[i+2][j]
            if main_diag_sum!=15 or off_diag_sum!=15:
                return False
            
            return True

        ans = 0
        for i in range(rows-3+1):
            for j in range(cols-3+1):

                # additional pruning based on center element, because this must be true for magic square
                if grid[i+1][j+1]!=5:
                    continue

                if isMagic(i, j):
                    ans += 1     
        return ans

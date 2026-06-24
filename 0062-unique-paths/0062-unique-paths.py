# TC- O(mn)
# SC- O(n)

class Solution:
    def uniquePaths(self, m: int, n: int) -> int:

        lastRow = [1]*n # base case for first row as it can always be reached only by going right
        for i in range(1, m):
            currentRow = [1]*n
            for j in range(1, n):
                currentRow[j] = lastRow[j] + currentRow[j-1]
            lastRow = currentRow
        return lastRow[n-1]
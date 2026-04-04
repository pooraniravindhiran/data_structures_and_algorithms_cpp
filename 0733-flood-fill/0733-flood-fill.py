# TC- O(mn)
# SC- O(mn)

class Solution:
    def dfs(self, image, rows, cols, r, c, old_color, new_color):
        image[r][c] = new_color
        dirs = [-1, 0, 1, 0, -1]
        for d in range(len(dirs)-1):
            next_r = r+dirs[d]
            next_c = c+dirs[d+1]
            if(next_r>=0 and next_r<rows and next_c>=0 and next_c<cols and image[next_r][next_c]==old_color):
                self.dfs(image, rows, cols, next_r, next_c, old_color, new_color)

    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        rows, cols = len(image), len(image[0])
        old_color = image[sr][sc]
        if old_color == color:
            return image
        self.dfs(image, rows, cols, sr, sc, old_color, color)
        return image
        
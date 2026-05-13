# TC- O(n^2)
# SC- O(n)

class Solution:
    def minAreaRect(self, points: List[List[int]]) -> int:
        # for every pair, check if they form a diagonal. If so, check if other 2 points exist. If so, then find area and track minimum. 

        points_set = set(map(tuple, points)) # hash set for quick lookup
        min_area = float('inf')
        n = len(points)
        for i in range(n):
            x1, y1 = points[i]

            for j in range(i+1, n):
                x2, y2 = points[j]

                if (x1!=x2) and (y1!=y2):
                    # check for other points
                    if (x1, y2) in points_set and (x2,y1) in points_set:
                        
                        h = abs(y2-y1)
                        w = abs(x2-x1)
                        area = h*w
                        min_area = min(area, min_area)
        
        min_area = 0 if min_area==float('inf') else min_area
        return min_area
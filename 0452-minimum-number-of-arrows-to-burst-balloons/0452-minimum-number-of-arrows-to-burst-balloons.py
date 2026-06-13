# TC- O(nlogn)
# SC- O(n)

class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort(key=lambda x:x[1])

        ans = 1
        end = points[0][1]
        for i in range(1, len(points)):
            if not(points[i][0]<=end<=points[i][1]):
                ans += 1
                end = points[i][1]

        return ans
            

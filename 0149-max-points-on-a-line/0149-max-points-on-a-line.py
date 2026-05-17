# SC- O(n)
# TC- O(n^2)

class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        # compare every pt with every other pt, compute slope and update count
        maxpts = 0
        n = len(points)

        for i in range(n):
            slope_count = defaultdict(int) # create dict inside this loop because different lines can have same slope
            curr_max = 0

            for j in range(i+1, n):

                pt_1, pt_2 = points[i], points[j]
                dy = pt_1[1]-pt_2[1]
                dx = pt_1[0]-pt_2[0]
                gcd = math.gcd(dy, dx) # (1,2), (2,4) are pts with same slope, so divide by gcd

                # handle vertical line
                if dx==0:
                    slope = (1, 0)
                
                # handle order of slope
                elif dx<0:
                    dx = -1*dx
                    dy = -1*dy
                    slope = (dy//gcd, dx//gcd)
                    
                else:
                    slope = (dy//gcd, dx//gcd ) #store ratio instead of float to avoid precision issue
                
                slope_count[slope] += 1
                curr_max = max(curr_max, slope_count[slope])
        
            maxpts = max(maxpts, curr_max+1)
        return maxpts



# TC- O(logk) where k is max(nums)
# SC- O(1)

class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        
        def caneat(k):
            hours = 0
            for pile in piles:
                hours += math.ceil(pile/k)
                if hours>h:
                    return False
            return True

        # binary search in ans space
        left, right = 1, max(piles)
        while left<right:
            mid = left+(right-left)//2

            if(caneat(mid)):
                right = mid
            else:
                left = mid+1
        return left
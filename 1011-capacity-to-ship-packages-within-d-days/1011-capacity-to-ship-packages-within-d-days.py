# TC- O(n*log(sum(wts)))
# SC- O(1)

class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        # do binary search in ans space- i.e capacity
        def canShip(capacity):
            curr_load, curr_days = 0, 1
            for w in weights:
                if curr_load+w >capacity:
                    curr_load = 0
                    curr_days += 1
                curr_load += w
            if curr_days>days:
                return False
            else:
                return True

        left = max(weights) # if not, we can never ship that weight
        right = sum(weights)

        while(left<right):
            mid = left+ (right-left)//2
            if canShip(mid):
                right = mid
            else:
                left = mid+1
        return left
        
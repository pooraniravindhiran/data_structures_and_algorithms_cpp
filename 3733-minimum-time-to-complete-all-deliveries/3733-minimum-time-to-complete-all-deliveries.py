# TC- O(log(max))
# SC- O(1)

from math import gcd

class Solution:
    def minimumTime(self, d: List[int], r: List[int]) -> int:
        total = sum(d)
        lcm = r[0] * r[1] // gcd(r[0], r[1])

        def canComplete(T):
            cap0 = T - T // r[0]
            cap1 = T - T // r[1]
            usable = T - T // lcm
            return min(d[0], cap0) + min(d[1], cap1) >= total and total <= usable

        left, right = 1, total*max(r)
        while left < right:
            mid = left + (right - left) // 2
            if canComplete(mid):
                right = mid
            else:
                left = mid + 1
        return left
# TC- O(logn)
# SC- O(1)

class Solution:
    def hammingWeight(self, n: int) -> int:
        
        res = 0

        while n:
            res += n&1
            n = n>>1
        
        return res
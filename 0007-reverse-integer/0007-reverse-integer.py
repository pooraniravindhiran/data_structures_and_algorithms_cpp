# TC- O(logn)
# SC- O(1)

class Solution:
    def reverse(self, x: int) -> int:
        ans = 0
        sign = -1 if x<0 else 1
        x = abs(x)
        INT_MAX = 2**31-1

        while(x):
            digit = x %10
            x = x//10
            if ans > ((INT_MAX-digit)//10):
                return 0
            ans = ans*10+digit

        return sign*ans
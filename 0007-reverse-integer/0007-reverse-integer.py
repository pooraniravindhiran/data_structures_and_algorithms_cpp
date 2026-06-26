# TC- O(logn)
# SC- O(1)

class Solution:
    def reverse(self, x: int) -> int:
        sign = -1 if x<0 else 1
        x = abs(x)
        INT_MAX = (1<<31)-1
        rev = 0
        while x:
            digit = x%10
            x = x//10
            if rev>((INT_MAX-digit)//10):
                return 0
            rev = (rev*10)+digit

        return sign*rev

# TC- O(1)
# SC- O(1)

class Solution:
    def getSum(self, a: int, b: int) -> int:
        mask = 0xffffffff
        # in python, there's no fixed 32 bit precision. so -1 is infinite precision. so b would never become 0 if you have a negative number in a. so i simulate 32 bit by masking
        while b:
            # print(b)
            carry = (a & b) & mask
            a = (a ^ b) & mask
            b = (carry<<1) & mask

        # Now a is 32 bit cropped version of a signed number, but it can be positive or negative. if positive we can return as such. else we need to represent it in a different form.
        return a if a<=0x7fffffff else a-(1<<32)
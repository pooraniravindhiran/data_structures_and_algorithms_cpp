class Solution:
    def getSum(self, a: int, b: int) -> int:
        mask = 0xffffffff
        # in python, there's no fixed 32 bit precision. so -1 is infinite precision. so b would never become 0. so i simulate 32 bit by masking
        while b:
            temp = a ^ b
            b = (a & b) <<1
            b = b & mask
            a = temp & mask

        # but masking makes the negative number reallly large, so handle that
        return a if a<=0x7fffffff else ~(a^mask)
# TC- O(logn) - logn for one getNext call, max num of times it can be called for 32 bit integer is 10*9*9 = 810, so O(logn*1)
# SC- O(1)

class Solution:
    def getNext(self, n):
        square_sum = 0
        while(n):
            rem = n%10
            square_sum += rem*rem
            n = n//10
        return square_sum

    def isHappy(self, n: int) -> bool:
        slowptr = n
        fastptr = self.getNext(n)
        while(fastptr!=1 and fastptr!=slowptr):
            slowptr = self.getNext(slowptr)
            fastptr = self.getNext(self.getNext(fastptr))
        return fastptr==1
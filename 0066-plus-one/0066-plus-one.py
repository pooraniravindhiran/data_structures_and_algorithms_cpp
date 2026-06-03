# TC- O(n)
# SC- O(1)

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        carry = 1
        n = len(digits)
        for i in range(n-1, -1, -1):
            temp_sum = digits[i]+carry
            digits[i] = temp_sum%10
            carry = temp_sum//10
        if carry == 1:
            digits.insert(0, 1)
        return digits
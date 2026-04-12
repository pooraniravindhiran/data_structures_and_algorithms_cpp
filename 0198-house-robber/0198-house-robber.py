# TC- O(n)
# SC- O(n)

class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        memo = {}

        def helper(i):
            if i in memo:
                return memo[i]

            if i>=n:
                return 0
            memo[i]= max(nums[i]+helper(i+2), helper(i+1))
            return memo[i]
        
        return helper(0)
# TC- O(n), SC- O(1)

class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        n = len(nums)
        for idx, curr in enumerate(nums):
            prev_num = nums[idx-1] if idx>=1 else float('-inf')
            next_num = nums[idx+1] if idx<n-1 else float('-inf')
            # print(prev_num, next_num)
            if curr>prev_num and curr>next_num:
                return idx
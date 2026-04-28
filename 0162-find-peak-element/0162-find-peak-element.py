# TC- O(logn), SC- O(1)
# I compare mid and mid+1.
# If I’m on an increasing slope, peak must be right.
# If I’m on a decreasing slope, peak must be left including mid.
# This lets me discard half the array each time.

class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        left = 0
        right = len(nums)-1
        while left<right:
            mid = left+(right-left)//2
            if nums[mid]<nums[mid+1]:
                left = mid+1
            elif nums[mid]>nums[mid+1]:
                right = mid
        return left


# TC- O(n), SC- O(1)
# class Solution:
#     def findPeakElement(self, nums: List[int]) -> int:
#         n = len(nums)
#         for idx, curr in enumerate(nums):
#             prev_num = nums[idx-1] if idx>=1 else float('-inf')
#             next_num = nums[idx+1] if idx<n-1 else float('-inf')
#             # print(prev_num, next_num)
#             if curr>prev_num and curr>next_num:
#                 return idx
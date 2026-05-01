# TC- O(logn)
# SC- O(1)

class Solution:
    def findMin(self, nums: List[int]) -> int:
        left = 0
        right = len(nums)-1
        
        while(left<right):
            mid = left + (right-left)//2
            if nums[mid]>nums[right]:
                left = mid +1
            else:
                right = mid
        return nums[left]

# class Solution:
#     def findMin(self, nums: List[int]) -> int:
#         left = 0
#         right = len(nums)-1
        
#         while(left<right):
#             if nums[left]<nums[right]:
#                 return nums[left]
#             mid = left + (right-left)//2
#             if nums[mid]>=nums[left]:
#                 left = mid +1
#             else:
#                 right = mid
#         return nums[left]
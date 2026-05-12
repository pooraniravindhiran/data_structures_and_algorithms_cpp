# TC- O(logn)
# SC- O(1)

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        # we can do binary search for efficiency. But to figure out which half we need to search, we need to first identify which half is sorted. Once you identify teh sorted half, you compare with target value in that half.
        left, right = 0, len(nums)-1

        while left<=right:
            mid = left+(right-left)//2

            if nums[mid]==target:
                return mid
            
            # left half is sorted
            if nums[left]<=nums[mid]:
                if nums[left]<=target<nums[mid]:
                    right = mid-1
                else:
                    left = mid+1
            
            # right half (including mid) is not sorted
            else:
                if nums[mid]<target<=nums[right]:
                    left = mid+1
                else:
                    right = mid-1
        return -1
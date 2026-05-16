# TC- O(nlogk)
# SC- O(1)

class Solution:
    def minimumSize(self, nums: List[int], maxOperations: int) -> int:
        def is_possible(max_bag_size):
            total_operations = 0
            for num in nums:
                operations = math.ceil(num/max_bag_size)-1
                total_operations += operations
                if total_operations > maxOperations:
                    return False
            return True

        # Perform binary search to find the optimal max_bag_size
        left, right = 1, max(nums)
        while left<right:
            mid = left +(right-left)//2

            if is_possible(mid):
                right = mid
            else:
                left = mid+1

        return left
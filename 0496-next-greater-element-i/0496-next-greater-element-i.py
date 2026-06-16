# TC- O(n)
# SC- O(n)

class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums2_map = {}
        stack = []
        for num in nums2:
            while stack and num>stack[-1]:
                nums2_map[stack.pop()] = num
            stack.append(num)
        # print(nums2_map)
        
        return [nums2_map.get(num, -1) for num in nums1]

# # TC- O(mn)
# # SC- O(n)

# class Solution:
#     def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
#         nums2_map = {val:idx for idx, val in enumerate(nums2)}

#         ans = [-1]*len(nums1)
#         for i in range(len(nums1)):

#             idx_nums2 = nums2_map[nums1[i]]+1
#             while(idx_nums2<len(nums2) and nums2[idx_nums2]<=nums1[i]):
#                 idx_nums2 += 1
            
#             if idx_nums2<len(nums2):
#                 ans[i] = nums2[idx_nums2]
#         return ans
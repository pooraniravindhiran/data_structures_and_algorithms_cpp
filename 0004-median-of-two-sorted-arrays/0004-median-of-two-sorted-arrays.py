class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        # Instead of merging the arrays, which takes O(m+n), I want to find a perfect cut through both arrays at the same time. This cut must divide the combined elements into two equal halves: a Left Pile and a Right Pile.
        #Since the total number of elements is fixed, if I move the cut in Array A to the right, the cut in Array B must move to the left to keep the halves equal.This means I only need to Binary Search for the cut position in one of the arrays. I pick smaller array as this gives us that O(log(min(m, n))).
        if len(nums1)>len(nums2):
            nums1, nums2 = nums2, nums1
        
        left, right = 0, len(nums1)
        half_len = (len(nums1)+len(nums2)+1)//2 #+1 is just to handle odd length total such that the middle element is in left and not right half

        while left<=right:
            mid_i = left+(right-left)//2
            mid_j = half_len-mid_i

            if mid_i<len(nums1) and nums2[mid_j-1]>nums1[mid_i]:
                left = mid_i+1
            elif mid_i>0 and nums1[mid_i-1]>nums2[mid_j]:
                right = mid_i-1
            else:
                if mid_i==0:
                    max_left = nums2[mid_j-1]
                elif mid_j==0:
                    max_left = nums1[mid_i-1]
                else:
                    max_left = max(nums2[mid_j-1], nums1[mid_i-1])

                # if total len is odd, then median is max_left
                if(len(nums1)+ len(nums2))%2==1:
                    return max_left

                # if total len is even, then median is avg of max_left and min_right
                else:
                    if mid_j==len(nums2):
                        min_right = nums1[mid_i]
                    elif mid_i==len(nums1):
                        min_right = nums2[mid_j]
                    else:
                        min_right = min(nums1[mid_i], nums2[mid_j])
                    return (max_left+min_right)/2



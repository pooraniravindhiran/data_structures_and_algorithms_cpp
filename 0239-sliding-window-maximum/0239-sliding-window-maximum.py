# TC- O(n)
# SC- O(k)

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        # Initially thought of sliding window and heap solution but it has TC O(nlogk). Better is O(n). Is it possible? Yes, use monotonic deque insead of heap.

        q = deque()
        ans = []

        for idx, num in enumerate(nums):
            # If a bigger number comes in, the previous smaller numbers no longer would be maximum. So remove them.
            while(q and nums[q[-1]]<num):
                q.pop()
            
            # Add current elem
            q.append(idx)

            # Remove any elements from front of deque that no longer are in the window
            if(q[0]<=idx-k):
                q.popleft()
            
            # update max value if window size reached
            if (idx>=k-1):
                ans.append(nums[q[0]])
        return ans


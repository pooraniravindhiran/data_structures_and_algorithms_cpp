# TC- O(n*logn)
# SC - O(n)

class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        
        # greedy method? doesnt work because it might span for a long time but sum of profits in that time might be more
        # at every job, you can either skip it, or take its profit and pick the next job whose start>=end

        memo = [-1]*len(startTime) # represents max profit starting at index i

        # sort jobs by start times
        jobs = list(zip(startTime, endTime, profit))
        jobs.sort()
        n = len(jobs)

        def nextHigher(i):
            left, right = 0, len(jobs)-1
            ans = n
            while left<=right: # ans might not be there
                mid = left+(right-left)//2
                if jobs[mid][0]<i:
                    left = mid+1
                else:
                    ans = mid
                    right = mid-1
            return ans

        def maxProfitFrom(i):
            if i==n:
                return 0

            if memo[i]!=-1:
                return memo[i]
            
            skip = maxProfitFrom(i+1)

            s,e,p = jobs[i]
            take = p + maxProfitFrom(nextHigher(e))

            memo[i] = max(skip, take)
            return memo[i]
            
        return maxProfitFrom(0)

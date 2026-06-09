# TC- O(mlogk)= O(mlog26)= O(m) where m is len(tasks) and k is distinct num of tasks
# SC- O(k)= O(26)= O(1)

class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        
        # min num of intervals mean you pick the most frequent task
        # freq map needed, priority for freq so heap needed, deque needed

        counter = Counter(tasks)

        max_heap = []
        for task, cnt in counter.items():
            heapq.heappush(max_heap, -cnt)
        print(max_heap)
        
        ans = 0
        waiting = deque()
        while max_heap or waiting:
            ans += 1

            if(waiting and waiting[0][1]==ans):
                print(waiting[0])
                freq, _ = waiting.popleft()
                heapq.heappush(max_heap, -freq)

            if max_heap:
                print("heap", max_heap[0])
                freq = -1*heapq.heappop(max_heap)
                freq -= 1
                if freq>0:
                    waiting.append((freq, ans+n+1))
                
        return ans
            

            
            

                

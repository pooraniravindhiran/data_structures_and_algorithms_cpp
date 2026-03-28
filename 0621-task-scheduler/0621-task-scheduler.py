# TC- O(n)
# SC- O(1)

class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        # create freq map
        cnts = Counter(tasks)

        # greedy approach- picking the task with highest freq helps reduce idle time
        # put the frequencies into a max_heap- doesn't matter which task
        max_heap = [-cnt for cnt in cnts.values()]
        heapq.heapify(max_heap)

        time = 0
        tasks_backto_heap = deque()
        while(max_heap or tasks_backto_heap):
            time += 1

            if(max_heap):
                cnt = 1+ heapq.heappop(max_heap)
                if cnt:
                    tasks_backto_heap.append([cnt, time+n])
            
            if(tasks_backto_heap and tasks_backto_heap[0][1]==time):
                heapq.heappush(max_heap, tasks_backto_heap.popleft()[0])
        
        return time

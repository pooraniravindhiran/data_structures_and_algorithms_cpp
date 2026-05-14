class MedianFinder:

    def __init__(self):
        self.min_heap = []
        self.max_heap = []

    def addNum(self, num: int) -> None:
        # TC- O(logn)
        if not self.max_heap or num<-self.max_heap[0]:
            heapq.heappush(self.max_heap, -num)
        else:
            heapq.heappush(self.min_heap, num)
        
        # balance
        if(len(self.min_heap)>len(self.max_heap)):
            top = heapq.heappop(self.min_heap)
            heapq.heappush(self.max_heap, -top)
        
        elif(len(self.max_heap)>len(self.min_heap)+1):
            top = heapq.heappop(self.max_heap)
            heapq.heappush(self.min_heap, -top)

    def findMedian(self) -> float:
        # TC- O(1)
        if len(self.min_heap)==len(self.max_heap):
            return (self.min_heap[0]-self.max_heap[0])/2
        else:
            return -self.max_heap[0]

# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
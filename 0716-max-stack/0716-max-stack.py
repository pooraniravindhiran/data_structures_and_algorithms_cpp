class MaxStack:

    def __init__(self):
        # stack to peek or pop last added element quickly
        # priority queue to peep or pop max element quickly
        # but element removed from stack should be updated in pq. but to do that you need to iterate through it. so just do lazy deletion
        # O(n)
        self.stack = []
        self.heap = []
        self.to_remove = set()
        self.cnt = 0 # to assign new id to each new element

    def push(self, x: int) -> None:
        # O(logn) = O(1)+O(logn)
        self.stack.append((x, self.cnt))
        heapq.heappush(self.heap, (-x, -self.cnt)) # since default is minheap
        self.cnt += 1

    def pop(self) -> int:
        # O(logn)- amortized
        while self.stack and self.stack[-1][1] in self.to_remove:
            self.stack.pop()
        num, idx = self.stack.pop()
        self.to_remove.add(idx)
        return num

    def top(self) -> int:
        # O(1)- amortized
        while self.stack and self.stack[-1][1] in self.to_remove:
            self.stack.pop()
        return self.stack[-1][0]

    def peekMax(self) -> int:
        while self.heap and -self.heap[0][1] in self.to_remove:
            heapq.heappop(self.heap)
        return -self.heap[0][0]

    def popMax(self) -> int:
        while self.heap and -self.heap[0][1] in self.to_remove:
            heapq.heappop(self.heap)
        num, idx = heapq.heappop(self.heap)
        self.to_remove.add(-idx)
        return -num

# Your MaxStack object will be instantiated and called as such:
# obj = MaxStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.peekMax()
# param_5 = obj.popMax()
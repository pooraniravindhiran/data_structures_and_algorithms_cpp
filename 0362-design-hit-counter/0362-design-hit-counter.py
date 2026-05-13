# SC- O(n)
class HitCounter:

    def __init__(self):
        self.times = [0]*300
        self.hits = [0]*300

    def hit(self, timestamp: int) -> None:
        # TC- O(1)
        idx = timestamp%300
        if self.times[idx]!=timestamp:
            self.times[idx]= timestamp
            self.hits[idx] = 1
        else:
            self.hits[idx] += 1

    def getHits(self, timestamp: int) -> int:
        # TC- O(1)
        total = 0
        for i in range(300):
            if timestamp-self.times[i]<300:
                total += self.hits[i]
        return total

# # many ts, each ts might have many hits
# # dict but more than 300, delete is difficult
# # queue is better

# # SC- O(n)
# class HitCounter:

#     def __init__(self):
#         self.q = deque()

#     def hit(self, timestamp: int) -> None:
#         # TC- O(1)
#         self.q.append(timestamp)

#     def getHits(self, timestamp: int) -> int:
#         # TC- O(1)
#         while self.q and self.q[0]<=timestamp-300:
#             self.q.popleft()
#         return len(self.q)
        

# Your HitCounter object will be instantiated and called as such:
# obj = HitCounter()
# obj.hit(timestamp)
# param_2 = obj.getHits(timestamp)
# SC- O(n)
class Node:
    def __init__(self, url):
        self.url = url
        self.prev = None
        self.next = None

class BrowserHistory:

    def __init__(self, homepage: str):
        self.curr = Node(homepage)

    def visit(self, url: str) -> None:
        # TC- O(1)
        node = Node(url)
        self.curr.next = node
        node.prev = self.curr
        self.curr = node

    def back(self, steps: int) -> str:
        # TC- O(1)
        while(steps>0 and self.curr.prev):
            self.curr = self.curr.prev
            steps -= 1
        return self.curr.url

    def forward(self, steps: int) -> str:
        # TC- O(1)
        while(steps>0 and self.curr.next):
            self.curr = self.curr.next
            steps -= 1
        return self.curr.url

# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)

# # SC- O(n)

# class BrowserHistory:

#     def __init__(self, homepage: str):
#         self.history = [homepage]
#         self.curr = 0

#     def visit(self, url: str) -> None:
#         # TC- O(n)
#         # remove forward history
#         self.history = self.history[:self.curr+1]

#         self.history.append(url)
#         self.curr += 1

#     def back(self, steps: int) -> str:
#         # TC- O(1)
#         self.curr = max(0, self.curr-steps)
#         return self.history[self.curr]

#     def forward(self, steps: int) -> str:
#         # TC- O(1)
#         self.curr = min(len(self.history)-1, self.curr+steps)
#         return self.history[self.curr]


# # Your BrowserHistory object will be instantiated and called as such:
# # obj = BrowserHistory(homepage)
# # obj.visit(url)
# # param_2 = obj.back(steps)
# # param_3 = obj.forward(steps)
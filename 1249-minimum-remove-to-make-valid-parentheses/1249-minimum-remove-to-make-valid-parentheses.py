# TC- O(n)
# SC- O(n)

class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        self.stack = []
        self.to_remove = set()

        for idx, ch in enumerate(s):
            if ch=='(':
                self.stack.append(idx)
            elif ch==')':
                if self.stack:
                    self.stack.pop()
                else:
                    self.to_remove.add(idx)

        if self.stack:
            self.to_remove.update(self.stack)
        
        ans = []
        for idx, ch in enumerate(s):
            if idx not in self.to_remove:
                ans.append(ch)
        return "".join(ans)


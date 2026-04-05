# TC- O(n)
# SC- O(n)

class Solution:
    def isValid(self, s: str) -> bool:
        self.stack = []

        for ch in s:
            if ch in ["(", "[", '{']:
                self.stack.append(ch)
            else:
                if not self.stack:
                    return False
                popped = self.stack.pop()
                if (ch==")" and popped is not "(") or (ch=="]" and popped is not "[") or (ch=="}" and popped is not "{"):
                    return False
        if self.stack:
            return False
        return True
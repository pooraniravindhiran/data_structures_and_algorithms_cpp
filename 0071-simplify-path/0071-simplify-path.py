# TC- O(n)
# SC- O(n)

class Solution:
    def simplifyPath(self, path: str) -> str:
        # if // or ///, just push /
        # remove trailing /
        # remove .
        # remove .. , pop previous
        self.stack = []
        for part in path.split("/"):
            if part=="" or part==".":
                continue
        
            elif part =="..":
                if self.stack:
                    self.stack.pop()
            
            else:
                self.stack.append(part)
        
        return "/"+"/".join(self.stack)
# TC- O(n)
# SC- O(n)

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for i in range(len(tokens)):
            ch = tokens[i]
            if ch == "+":
                b = int(stack.pop())
                a = int(stack.pop())
                stack.append(str(a+b))
            
            elif ch == "-":
                b = int(stack.pop())
                a = int(stack.pop())
                stack.append(str(a-b))
            
            elif ch == "*":
                b = int(stack.pop())
                a = int(stack.pop())
                stack.append(str(a*b))
            
            elif ch == "/":
                b = int(stack.pop())
                a = int(stack.pop())
                # print(a, b, int(a/b), "Hellow")
                stack.append(str(int(a/b)))
            
            else:
                stack.append(ch)
            # print(stack[-1], " ")
        return int(stack[-1])

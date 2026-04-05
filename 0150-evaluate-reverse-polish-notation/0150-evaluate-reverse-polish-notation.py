# TC- O(n)
# SC- O(n)

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        ans = 0
        stack = []

        for ch in tokens:
            if ch in ["+", "-", "/", "*"]:
                num2 = int(stack.pop())
                num1 = int(stack.pop())
                if ch == "+":
                    stack.append(num1+num2)
                elif ch == "-":
                    stack.append(num1-num2)
                elif ch == "*":
                    stack.append(num1*num2)
                else:
                    stack.append(int(num1/num2))
                print(num1, num2, stack[-1])
            else:
                stack.append(ch)
        
        return int(stack[-1])

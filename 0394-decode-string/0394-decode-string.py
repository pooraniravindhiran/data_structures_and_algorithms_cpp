# TC- O(n)
# SC- O(n)

class Solution:
    def decodeString(self, s: str) -> str:
        
        n = len(s)
        stack = []

        for ch in s:

            # keep pushing until you see ']'
            if ch != ']':
                stack.append(ch)

            # then pop until you see '['
            else:
                # get num and str
                substr = ""
                while(stack[-1]!='['):
                    substr = stack.pop() + substr
                stack.pop()
                num = ""
                while(stack and stack[-1].isdigit()):
                    num = stack.pop() + num

                # compute decoded str
                decoded = substr*int(num)

                # psuh decoded str
                for c in decoded:
                    stack.append(c)
            
        return "".join(stack)
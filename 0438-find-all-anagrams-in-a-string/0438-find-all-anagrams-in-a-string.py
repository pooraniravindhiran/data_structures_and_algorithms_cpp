# TC- O(n)
# SC- O(1)

class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        ans = []
        if len(p)>len(s):
            return ans

        p_count = [0]*26
        s_count = [0]*26
        for ch in p:
            p_count[ord(ch)-ord('a')] += 1
        
        left = 0
        for right in range(len(p)):
            s_count[ord(s[right])-ord('a')]+= 1
        if p_count==s_count:
            ans.append(left)

        for right in range(len(p), len(s)):
            s_count[ord(s[right])-ord('a')] +=1     
            s_count[ord(s[left])-ord('a')] -= 1
            left += 1
            if p_count==s_count:
                ans.append(left)
        
        return ans
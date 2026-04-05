# TC- O(n)
# SC- O(1)

class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:

        # count letters in s1
        count = [0]*26
        for ch in s1:
            count[ord(ch)-ord('a')]+= 1
        
        # slide window over s2 and compare each window
        window = [0]*26
        for ch in s2[0:len(s1)]:
            window[ord(ch)-ord('a')]+=1
        
        if count==window:
            return True
        
        for i in range(len(s1), len(s2)):
            window[ord(s2[i])-ord('a')] += 1 # add new char
            window[ord(s2[i-len(s1)])-ord('a')] -= 1 # remove old char
            if count==window:
                return True
        return False
        

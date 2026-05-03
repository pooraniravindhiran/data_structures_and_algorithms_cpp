# TC- O(n)
# SC- O(min(n, charset))

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        last_occ = {}
        left = 0
        max_len = 0
        for right in range(len(s)):
            if s[right] in last_occ:
                left = max(left, last_occ[s[right]]+1)
            max_len = max(max_len, right-left+1)
            last_occ[s[right]] = right
        return max_len
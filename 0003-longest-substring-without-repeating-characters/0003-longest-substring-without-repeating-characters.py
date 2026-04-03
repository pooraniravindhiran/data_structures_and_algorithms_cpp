# TC- O(n)
# SC- O(min(n, charset))

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        last_index = {}
        ans = 0
        start = 0

        for end, ch in enumerate(s):
            if ch in last_index and start<=last_index[ch]:
                start = last_index[ch]+1
            last_index[ch] = end
            ans = max(ans, end-start+1)
        return ans     
# TC- O(n)
# SC- O(min(n, charset))

class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        start = maxfreq= maxlen = 0
        freq = {}

        for end, ch in enumerate(s):
            freq[ch] = freq.get(ch, 0)+1
            maxfreq = max(maxfreq, freq[ch])

            while((end-start+1-maxfreq)>k):
                freq[s[start]] -= 1
                start += 1
            maxlen = max(maxlen, end-start+1)
        return maxlen
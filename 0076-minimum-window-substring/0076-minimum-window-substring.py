# TC- O(s+t)
# SC- O(s+t)

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        need_map = Counter(t)
        need_len = len(need_map)

        window_map = {}
        have_len = 0

        res, res_len = (-1, -1), float('inf') # leftidx, rightidx, maxlen
        left = 0
        for right in range(len(s)):
            ch = s[right]
            window_map[ch] = 1+window_map.get(ch, 0)

            if ch in need_map and need_map[ch]==window_map[ch]:
                have_len += 1
            
            while need_len==have_len:

                if (right-left+1)<res_len:
                    res_len = right-left+1
                    res = (left, right)
            
                left_ch = s[left]
                left +=1
                window_map[left_ch] -= 1
                if left_ch in need_map and window_map[left_ch]<need_map[left_ch]:
                    have_len-=1

        return s[res[0]:res[1]+1] if res_len!=float('inf') else ""

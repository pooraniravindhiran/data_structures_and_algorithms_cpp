# TC- O(nlogk)
# SC- O(1)

class Solution:
    def reorganizeString(self, s: str) -> str:
        # To avoid adjacent duplicates, always place the character with the highest remaining frequency, but make sure we don’t use the same character twice in a row.
        
        # Push the chars into a max_heap by their freq of occ
        max_heap = []
        freq_map = Counter(s) 
        for ch, freq in freq_map.items():
            heapq.heappush(max_heap, (-freq, ch))
        
        result = []
        prev = None
        while max_heap:
            # pop top element
            freq, ch = heapq.heappop(max_heap)

            result.append(ch)

            if prev and prev[0]!=0:
                heapq.heappush(max_heap, prev)

            # decrement it and if not 0, push it back
            freq += 1
            prev = (freq, ch)

        res = "".join(result)
        return res if len(res)==len(s) else ""

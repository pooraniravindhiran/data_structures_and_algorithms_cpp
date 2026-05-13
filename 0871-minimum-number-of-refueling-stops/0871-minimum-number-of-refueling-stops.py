# TC- O(nlogn)
# SC- O(n)

class Solution:
    def minRefuelStops(self, target: int, startFuel: int, stations: List[List[int]]) -> int:
        max_heap = []
        stations.append((target, float('inf')))
        min_stops = 0

        curr_fuel = startFuel
        curr_pos = 0
        for loc, fuel in stations:
            curr_fuel -= loc-curr_pos
            while max_heap and curr_fuel<0:
                curr_fuel += -heapq.heappop(max_heap)
                min_stops += 1
            if curr_fuel<0:
                return -1
            heapq.heappush(max_heap, -fuel)
            curr_pos = loc
        return min_stops
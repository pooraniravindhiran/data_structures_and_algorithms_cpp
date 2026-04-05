# TC- O(nlogn)
# SC- O(n)

class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        cars = sorted(zip(position, speed), reverse=True)

        num_fleets = 0
        prev_time_to_target = 0
        for pos, spd in cars:
            curr_time_to_target = (target-pos)/spd
            if curr_time_to_target > prev_time_to_target:
                num_fleets += 1
                prev_time_to_target = curr_time_to_target
        
        return num_fleets
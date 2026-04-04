# TC- O(n)
# SC- O(n)

class Solution:
    def getDistances(self, arr: List[int]) -> List[int]:
        indices_map = defaultdict(list)

        for idx, num in enumerate(arr):
            indices_map[num].append(idx)
        
        ans = [0]*len(arr)
        for num, indices in indices_map.items():
            if len(indices)==1:
                continue
            k = len(indices)
            total_sum = sum(indices)
            running_sum = 0

            for i in range(k):
                curr_idx = indices[i]
                left_sum = (i*curr_idx) - running_sum # (ij-io)+(ij-i1)+(ij-i2)...

                running_sum += curr_idx
                right_sum = (total_sum-running_sum) - ((k-i-1)*curr_idx)
                ans[curr_idx] = left_sum + right_sum
            
        return ans

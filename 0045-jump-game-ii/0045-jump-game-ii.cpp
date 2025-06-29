// TC- O(n)
// SC- O(1)

class Solution {
public:
    int jump(vector<int>& nums) {
        int farthest = 0; // maximum you can reach so far
        int current_end = 0; // range of current jump- check all possibilities
        int jumps = 0; // minimum number of jumps to reach end from index 0
        for(int i=0; i<nums.size()-1; i++){
            farthest = max(farthest, i+nums[i]);

            if(i==current_end){
                jumps++;
                current_end = farthest;
            }
        }
        return jumps;
    }
};
// TC- O(n)
// SC- O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_sum = nums[0];
        int max_sum = curr_sum;
        for(int i=1; i<nums.size(); i++){
            curr_sum = max(curr_sum+nums[i], nums[i]);
            max_sum = max(max_sum, curr_sum);
        }
        return max_sum;
    }
};
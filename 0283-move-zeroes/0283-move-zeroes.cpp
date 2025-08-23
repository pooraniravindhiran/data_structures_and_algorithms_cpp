class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zerop = 0;
        for(int curr=0; curr<nums.size(); curr++){
            if(nums[curr]!=0){
                nums[zerop] = nums[curr];
                if(curr!=zerop)
                    nums[curr] = 0;
                zerop++;
            }
        }
    }
};
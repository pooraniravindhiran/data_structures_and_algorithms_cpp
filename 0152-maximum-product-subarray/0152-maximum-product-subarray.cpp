// TC- O(n)
// SC- O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxpdt = nums[0];
        int max_currpdt = nums[0];
        int min_currpdt = nums[0];

        for(int i=1; i<nums.size(); i++){
            if(nums[i]<0)
                swap(max_currpdt, min_currpdt);
                
            max_currpdt = max(max_currpdt*nums[i], nums[i]);
            min_currpdt = min(min_currpdt*nums[i], nums[i]);
            maxpdt = max(maxpdt, max_currpdt);
        }
        return maxpdt;
    }
};

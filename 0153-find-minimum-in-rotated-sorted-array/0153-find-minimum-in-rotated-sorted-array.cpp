// TC- O(logn)
// sc- o(1)

class Solution {
public:
    int findMin(vector<int>& nums) {
        // edge case
        if(nums.size()==1)
            return nums[0];


        int lo = 0;
        int hi = nums.size()-1;

        // array is not rotated
        if(nums[hi]>nums[lo])
            return nums[lo];
        
        // array is rotated
        while(lo<hi){
            int mid = lo +(hi-lo)/2;
            if(nums[mid]>nums[hi])
                lo=mid+1;
            else
                hi=mid;
        }
        return nums[lo];
    }
};
// 1 2 3 4 5
// 3 4 5 1 2
// 1 2 3 4 5


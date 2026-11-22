// TC- O(logn)
// SC- O(1)
 
class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        
        while(left<right){
            int mid = left+(right-left)/2;
            
            int num_to_be_at_mid = nums[0]+mid;
            int nums_missing = nums[mid]-num_to_be_at_mid;
            
            if(nums_missing<k)
                left = mid+1;
            else
                right = mid;
        }

        // 2 possibilities
        // possibility 1- missing num is after last idx
        int nums_missing = nums[left]-(nums[0]+left);
        if(nums_missing<k)
            return nums[left] + (k-nums_missing);
        
        // possibility 2- left points to the first index where missing >= k
        // ans is between nums[left-1] and nums[left]
        // ans is nums[left-1] + (k-numsmissingbeforeleft-1)
        // ans is nums[left-1] + k - (nums[left-1]-nums[0]+1-left);
        // ans is k+nums[0]-1+left
        return k+nums[0]-1+left;
    }
};
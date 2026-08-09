// TC- O(n* log(sum(nums))) where O(n) is the TC for cansplit
// SC- O(1)

class Solution {
private:
    bool canSplit(vector<int>& nums, int k, int mid){
        // can we split nums into k subarrays such that largest sum of any subarray <=mid
        int curr_sum = 0;
        int subarrays = 1;

        for(int num:nums){
            if((curr_sum+num)<=mid)
                curr_sum += num;
            else{
                subarrays++;
                curr_sum = num;

                if(subarrays>k)
                    return false;
            }
        }
        return true;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        // binary search on ans space

        int left = *max_element(nums.begin(), nums.end()); // max element in array
        int right = accumulate(nums.begin(), nums.end(), 0); // sum of array
        while(left<right){
            int mid = left +(right-left)/2;
            if(canSplit(nums, k, mid))
                right = mid;
            else
                left = mid+1;
        }
        return left;
    }
};
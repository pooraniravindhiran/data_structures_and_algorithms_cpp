// TC- O(nlogn+ n^2)
// SC- O(logn)

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result;
        int min_diff = INT_MAX;
        // sorting makes this faster
        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size(); i++){
            int left=i+1;
            int right=nums.size()-1;
            while(left<right){
                int sum = nums[i]+ nums[left]+nums[right];
                int diff = abs(target-sum);
                if(diff==0)
                    return sum;
                else if(diff<min_diff){
                    min_diff = diff;
                    result = sum;
                }
                else if(sum<target)
                    left++;
                else
                    right--;
            }
        }
        return result;
    }
};
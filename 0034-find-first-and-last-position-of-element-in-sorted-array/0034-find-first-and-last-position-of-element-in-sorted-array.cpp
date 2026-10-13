class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left= 0;
        int right = nums.size()-1;

        // find first occ
        int ans = -1;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(nums[mid]<target)
                left = mid+1;
            else{
                if(nums[mid]==target)
                    ans = mid;
                right = mid-1;
            }
        }

        vector<int> res;
        res.push_back(ans);

        // find last occ
        ans = -1;
        left= 0;
        right = nums.size()-1;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(nums[mid]>target)
                right = mid-1;
            else{
                if(nums[mid]==target)
                    ans = mid;
                left = mid+1;
            }
        }

        res.push_back(ans);
        return res;
    }
};
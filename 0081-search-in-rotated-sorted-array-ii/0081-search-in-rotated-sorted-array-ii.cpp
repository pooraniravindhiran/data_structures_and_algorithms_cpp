class Solution {
public:
    bool search(vector<int>& nums, int target) {

        int l=0;
        int r=nums.size()-1;
        while(l<=r){
            int mid = l+ (r-l)/2;
            cout<<l<<" "<<r<<" "<<mid<<endl;
            if(nums[mid]==target)
                return true;
            else if(nums[l]==nums[mid])
                l++;
            else if(nums[l]<nums[mid]){
                // left subarray is sorted
                if(target<nums[mid] and target>=nums[l])
                    r = mid-1;
                else
                    l = mid+1;
            }
            else
                // right subarray is sorted
                if(target>nums[mid] and target<=nums[r])
                    l = mid+1;
                else
                    r = mid-1;
        }
        return false;
    }
};
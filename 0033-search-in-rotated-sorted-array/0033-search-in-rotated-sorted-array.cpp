// TC- O(logn)
// SC- O(1)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 0 1 2 4 5 6 7 - check left if not rotated
        // 4 5 6 7 0 1 2 - check right
        // 7 0 1 2 4 5 6 - check left
        // 3 4 5 6 7 1 2 - 

        // if only one element
        if(nums.size()==1 and nums[0]==target)
            return 0;
        
        int l=0;
        int r=nums.size()-1;
        while(l<=r){
            int mid = l+ (r-l)/2;
            cout<<l<<" "<<r<<" "<<mid<<endl;
            if(nums[mid]==target)
                return mid;
            else if(nums[l]<=nums[mid]){
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
        return -1;
    }
};
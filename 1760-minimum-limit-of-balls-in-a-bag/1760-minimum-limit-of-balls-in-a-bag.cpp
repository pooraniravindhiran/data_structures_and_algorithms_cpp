// TC- O(nlogn) + O(nlog(max))
// SC- O(1)

class Solution {
private:
    bool is_possible(int mid, int maxoper, vector<int>& nums){
        int oper = 0;
        int i = 0;
        while(i<nums.size()){
            if(nums[i]>mid)
                oper += (nums[i]-1)/mid;
            i++;
        }
        if(oper>maxoper)
            return false;
        return true;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());

        sort(nums.rbegin(), nums.rend());

        int ans = right;
        while(left<right){
            int mid = left+(right-left)/2;

            if(is_possible(mid, maxOperations, nums)){
                ans = mid;
                right = mid;
            }
            else
                left = mid+1;
        }
        return ans;
    }
};
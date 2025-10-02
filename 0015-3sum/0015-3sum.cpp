// TC- O(nlogn)+ O(n*n) = O(n^2)
// SC- O(logn)
class Solution {
private:
    void twosum(vector<int>& nums, int i, vector<vector<int>>& triplets){
        for(int lo=i+1, hi=nums.size()-1; lo<hi;){
            int sum = nums[lo]+nums[hi]+nums[i];
            if(sum==0){
                triplets.push_back({nums[i], nums[lo], nums[hi]});
                lo++;
                hi--;
                while(lo<hi and nums[lo]==nums[lo-1])
                    lo++;
            }
            else if(sum<0)
                lo++;
            else   
                hi--;

        }
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0)
                break;
            if(i>0 and nums[i]==nums[i-1])
                continue;
            twosum(nums, i, triplets);
        }
        return triplets;
    }
};
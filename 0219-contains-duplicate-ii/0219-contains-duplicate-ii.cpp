//TC- O(n)
//SC- O(n)

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for(int e=0; e<nums.size(); e++){
            if(hash.find(nums[e])!=hash.end() and abs(hash[nums[e]]-e)<=k){
                return true;
            }
            hash[nums[e]] = e;
        }
        return false;
    }
};
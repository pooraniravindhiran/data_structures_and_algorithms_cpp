// TC- O(n)
// SC- O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res;
        int count = 0;
        for(auto num:nums){
            if(count==0)
                res = num;
            if(res==num)
                count++;
            else
                count--;
        }
        return res;
    }
};
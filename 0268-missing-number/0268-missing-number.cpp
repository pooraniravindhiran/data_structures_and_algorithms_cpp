// TC- O(n)
// SC- O(1)

// If one pass- I could also use math formula n*(n+1)/2.
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int s = nums.size();
        int result = 0;
        for(int i =1; i<=s; i++)
            result = result ^ i;
        for(int i=0; i<nums.size(); i++)
            result = result ^ nums[i];
        return result;
    }
};
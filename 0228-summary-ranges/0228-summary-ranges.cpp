// TC - O(n)
// SC - O(1)

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int temp;
        for(int i=0; i<nums.size(); i++){
            temp = nums[i];
            while(i+1<nums.size() and nums[i+1]==nums[i]+1){
                i++;
            }
            if(temp == nums[i])
                result.push_back(to_string(temp));
            else{
                string s = to_string(temp) + "->" + to_string(nums[i]);
                result.push_back(s);
            }
        }
        return result;
    }
};
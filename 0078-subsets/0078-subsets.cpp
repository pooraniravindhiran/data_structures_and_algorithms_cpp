class Solution {
private:
    vector<vector<int>> result;
    void backtrack_helper(vector<int> &nums, vector<int>& curr, int start){
        result.push_back(curr);

        for(int i=start; i<nums.size(); i++){
            curr.push_back(nums[i]);
            backtrack_helper(nums, curr, i+1);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        backtrack_helper(nums, curr, 0);
        return result;
    }
};
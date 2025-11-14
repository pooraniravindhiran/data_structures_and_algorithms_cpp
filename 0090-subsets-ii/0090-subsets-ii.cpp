// TC- O((2^n)*n)
// SC- O(n) - recursion depth + curr max size

class Solution {
private:
    void backtracking_helper(vector<int> &nums, vector<vector<int>>& result, int index, vector<int>& curr, bool previncluded){
        // base case
        if(index==nums.size()){
            result.push_back(curr);
            return;
        }

        // iterate through choices- include current index, exclude current index
        // first choice- always exclude
        backtracking_helper(nums, result, index+1, curr, false);

        // second choice- include (if it is at index 0) or (if it is not a dup) or (if it is a duplicate and prev elem was included)
        if(index==0 or nums[index]!=nums[index-1] or previncluded){
            curr.push_back(nums[index]);
            backtracking_helper(nums, result, index+1, curr, true);

            // backtrack
            curr.pop_back();
        }     
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        backtracking_helper(nums, result, 0, curr, false);
        return result;
    }
};
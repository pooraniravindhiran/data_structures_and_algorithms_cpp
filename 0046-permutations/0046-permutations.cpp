// SC- O(n) recursion_stack, curr, used
// TC- O(n*n!) as there are n! permutations and copying from curr takes O(n) times for every permutation

class Solution {
private:
    void backtracking_helper(vector<int> & nums, vector<vector<int>> & result, vector<bool>& used, vector<int>& curr){
        // base case
        if(curr.size()==nums.size()){
            result.push_back(curr);
            return;
        }

        // iterate through choices- any number that is unused
        for(int i=0; i<nums.size(); i++){
            if(used[i])
                continue;
            
            // include it
            curr.push_back(nums[i]);
            used[i] = true;
            backtracking_helper(nums, result, used, curr);

            // backtrack
            used[i] =false;
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<bool> used(nums.size(), false);
        vector<int> curr;
        backtracking_helper(nums, result, used, curr);
        return result;
    }
};
//TC- n ^ (max depth of tree +1)= n^((T/M) +1) because given M being the minimal value amongst candidates and T be the target
// SC- curr + recursion call stack depth= O(T/M)

class Solution {
private:
    void backtracking_helper(vector<int>& candidates, vector<vector<int>>& result, vector<int>& curr, int target, int index){
        // base case
        if(target==0){
            result.push_back(curr);
            return;
        }
        
        // prune
        if(target<0)
            return;

        // iterate through choices- all numbers starting from current index. ignoring prev ones just to avoid dup sets
        for(int i=index; i<candidates.size(); i++){
            // skip duplicate for the same recursion depth
            if(i>index and candidates[i]==candidates[i-1])
                continue;

            curr.push_back(candidates[i]);
            backtracking_helper(candidates, result, curr, target-candidates[i], i+1);
            
            // backtrack
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        backtracking_helper(candidates, result, curr, target, 0);
        return result;
    }
};






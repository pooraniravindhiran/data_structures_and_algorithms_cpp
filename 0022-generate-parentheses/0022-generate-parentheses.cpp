// TC-O()
// SC-O(n)

class Solution {
    vector<string> result;
    void backtracking(int n, int openCount, int closeCount, string curr){
        // if base case is met, add it to the result and return
        if(curr.length()==2*n){
            result.push_back(curr);
            return;
        }

        // if number of open brackets is less, then add it. Iterate. Backtrack.
        if(openCount<n){
            backtracking(n, openCount+1, closeCount, curr+"(");
        }
        
        // if number of close brackets is less than number of open brackets, then add it. Iterate. Backtrack.
        if(openCount>closeCount){
            backtracking(n, openCount, closeCount+1, curr+")");
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        backtracking(n, 0, 0, "");
        return result;
    }
};
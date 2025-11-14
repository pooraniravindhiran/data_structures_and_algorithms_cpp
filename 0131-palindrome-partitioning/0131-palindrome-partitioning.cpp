// SC- O(n^2)
// TC- O(exponential)

class Solution {
private:
    vector<vector<bool>> mem;
    bool isPalindrome(int i, int j){
        return mem[i][j];
    }

    void backtracking_helper(string& s, vector<vector<string>>& result, vector<string>& curr, int index){
        // base case
        if(index==s.length()){
            result.push_back(curr);
            return;
        }

        // choices - every substring starting at index
        for(int end=index; end<s.size(); end++){
            string candidate = s.substr(index, end-index+1);
            if(isPalindrome(index, end)){
                curr.push_back(candidate);
                backtracking_helper(s, result, curr, end+1);
                curr.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> curr;

        // compute palindromes for string s 
        mem.resize(s.size(), vector<bool>(s.size(), false));
        for(int length=1; length<=s.length(); length++){
            for(int start=0; start<=s.length()-length; start++){
                int end = start + length -1;
                if(length==1)
                    mem[start][end] = true;
                else if(length==2)
                    mem[start][end] = (s[start]==s[end]);
                else
                    mem[start][end] = (s[start]==s[end]) and mem[start+1][end-1];
            }
        }

        backtracking_helper(s, result, curr, 0);
        return result;
    }
};
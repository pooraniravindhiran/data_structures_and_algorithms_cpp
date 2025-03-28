// TC- O(n)
// SC- O(n)

class Solution {
public:
    int numDecodings(string s) {
        // edge case
        if(s.size()==0)
            return 0;
        
        // base cases
        // dp[i] denotes num of ways you can decode string from index 0 upto i-1
        vector<int> dp(s.size()+1, 0);
        dp[0] = 1;
        // check for first char
        if(s[0]=='0')
            return 0;
        else
            dp[1] = 1;
        
        // recurrence relation
        for(int i=2; i<dp.size(); i++){
            if(s[i-1]!='0')
                dp[i] += dp[i-1];
            if(stoi(s.substr(i-2, 2))>=10 and stoi(s.substr(i-2, 2))<=26)
                dp[i] += dp[i-2];
        }

        return dp[s.size()];
    }
};
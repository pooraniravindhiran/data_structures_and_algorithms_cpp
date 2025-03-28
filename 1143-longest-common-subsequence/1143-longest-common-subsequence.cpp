// TC- O(mn)
// SC - O(mn)

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // dp[i+1][j+1] stores LCS of text1[0..i] and text2[0..j]
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        // base case- when letter is not common i.e either string is empty 
        // dp[i][0] for all i =0
        // dp[0][j] for all j =0

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(text1[i-1]==text2[j-1])
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        // string lcs;
        // int i=m;
        // int j=n;
        // while(i>0 and j>0){
        //     if(text1[i-1]==text2[j-1]){
        //         lcs += text1[i-1];
        //         i--;
        //         j--;
        //     }
        //     else if(dp[i-1][j]>dp[i][j-1])
        //         i--;
        //     else
        //         j--;
        // }
        // reverse(lcs.begin(), lcs.end());
        // cout<<lcs;
        
        return dp[m][n];
    }
};

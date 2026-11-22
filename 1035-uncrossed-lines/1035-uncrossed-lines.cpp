// TC- O(mn)
// SC- O(mn)

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        // Uncrossed lines → relative order must be preserved → common subsequence → maximize its length → LCS → DP.
        
        int m = nums1.size();
        int n = nums2.size();
        
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        // dp[i][j] represents the max uncrossed lines with first i elements in nums1 and first j elements in nums2
        
        for(int i=1; i<m+1; i++){
            for(int j=1; j<n+1; j++){
                if(nums1[i-1]==nums2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};

// 0, 3- 0, 4
// 5- 3
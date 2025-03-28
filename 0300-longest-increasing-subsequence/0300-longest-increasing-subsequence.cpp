// TC- O(n^2) (explanation- 1 + 2+ ... n = n*(n+1)/2 )
// SC- O(n)

class Solution {
private:
    
public:
    int lengthOfLIS(vector<int>& nums) {

        // Step 1: Array to represent ans i.e length of longest increasing subsequence
        // so dp[i] stores the LIS ending at i. ans at dp[n]
        vector<int> dp(nums.size(), 1);

        // Step 2: Base case
        // Assign 1 initially as every number could be considered as a subsequence by itself

        // Step 3: Recurrence relation
        // if nums[i]>nums[j], dp[i] = max(dp[i], dp[j]+1 where j<i)
        for(int i=1; i<dp.size(); i++){
            for(int j=0; j<i; j++){
                if(nums[j]<nums[i])
                    dp[i] = max(dp[i], dp[j]+1);
            }
        }

        // check for max in dp
        int ans = INT_MIN;
        for(int i=0; i<dp.size(); i++)
            ans = max(ans, dp[i]);
        return ans;
    }
};

// To print LIS, keep track of indices using another vector.
// TC- O(n^2) (explanation- 1 + 2+ ... n = n*(n+1)/2 )
// SC- O(n)

// class Solution {
// private:
    
// public:
//     int lengthOfLIS(vector<int>& nums) {

//         int max_len=1;
//         int last_index=0;

//         // Step 1: Array to represent ans i.e length of longest increasing subsequence
//         // so dp[i] stores the LIS ending at i. ans at dp[n]
//         vector<int> dp(nums.size(), 1);

//         // To print sequence, we need to keep track of elements
//         // prev[i] gives the index of the previous element in the LIS ending at nums[i]
//         vector<int> prev_index(nums.size(), -1);

//         // Step 2: Base case
//         // Assign 1 initially as every number could be considered as a subsequence by itself

//         // Step 3: Recurrence relation
//         // if nums[i]>nums[j], dp[i] = max(dp[i], dp[j]+1 where j<i)
//         for(int i=1; i<dp.size(); i++){
//             for(int j=0; j<i; j++){
//                 if(nums[j]<nums[i] and dp[j]+1>dp[i]){
//                     prev_index[i] = j;
//                     dp[i] = dp[j]+1;
//                 }
//             }

//             if(dp[i]>max_len){
//                 max_len = dp[i];
//                 last_index = i;
//             }
//         }

//         // print LIS
//         for(int i=last_index; i!=-1; i=prev_index[i]){
//             cout<<nums[i]<<" ";
//         }
//         return max_len;
//     }
// };
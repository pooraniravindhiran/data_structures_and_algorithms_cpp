// TC- O(n)
// SC- O(n)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> freqtable;
        freqtable[0] = 1;

        // if prefix_sum[j]-prefix_sum[i] == 0, then sum of elements lying between these indices is 0. Similarly, sum of elementts lying between two indices is k if prefix_sum[j]-prefix_sum[i] == k.
        int prefix_sum = 0;
        int ans = 0;
        for(int i=0; i<n; i++){
            prefix_sum += nums[i];

            if(freqtable.find(prefix_sum-k)!=freqtable.end())
                ans += freqtable[prefix_sum-k];
                
            if(freqtable.find(prefix_sum) != freqtable.end())
                freqtable[prefix_sum] ++;
            else
                freqtable[prefix_sum] = 1;
                
        }
        return ans;
    }
};

// // TC- O(n^2)
// // SC- O(1)

// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int n = nums.size();
        
//         // iterate through every pair and check diff between prefix_sum
//         int ans = 0;
//         for(int start=0; start<n; start++){
//             int sum = 0;
//             for(int end=start; end<n; end++){
//                 sum += nums[end];
//                 if(sum==k)
//                     ans++;
//             }
//         }
        
//         return ans;
//     }
// };



// // TC- O(n^2)
// // SC- O(n)

// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<int> prefix_sum(n+1, 0);

//         // find prefix sum
//         for(int i=1; i<=n; i++)
//             prefix_sum[i] = prefix_sum[i-1]+nums[i-1];

//         // iterate through every pair and check diff between prefix_sum
//         int ans = 0;
//         for(int start=0; start<n; start++){
//             for(int end=start+1; end<=n; end++){
//                 if(prefix_sum[end]-prefix_sum[start]==k)
//                     ans++;
//             }
//         }
        
//         return ans;
//     }
// };



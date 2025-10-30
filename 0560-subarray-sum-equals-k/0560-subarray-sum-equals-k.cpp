// TC- O(n^2)
// SC- O(n)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix_sum(n+1, 0);

        // find prefix sum
        for(int i=1; i<=n; i++)
            prefix_sum[i] = prefix_sum[i-1]+nums[i-1];

        // iterate through every pair and check diff between prefix_sum
        int ans = 0;
        for(int start=0; start<n; start++){
            for(int end=start+1; end<=n; end++){
                if(prefix_sum[end]-prefix_sum[start]==k)
                    ans++;
            }
        }
        
        return ans;
    }
};



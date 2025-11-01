// TC- O(n)
// SC- O(k) as prefix_mods can go upto k only

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // subarray from i+1 to j % k == 0
        // prefix_sum[j]-prefix_sum[i] % k ==0
        // (q1*k+r1 - q2*k+r2) % k ==0
        // r1-r2 %k == 0
        // r1 == r2
        // prefix_sum(j)modk == prefix_sum(i)modk

        unordered_map<int, int> freq;
        int ans = 0;
        int prefix_mod = 0;
        freq[0] = 1;
        for(int i=0; i<nums.size(); i++){
            prefix_mod = (prefix_mod+nums[i])%k;
            if(prefix_mod<0)
                prefix_mod += k; // math modulo should be positive between [0, k)- cyclical
            if(freq.find(prefix_mod)!=freq.end()){
                ans += freq[prefix_mod]; 
                freq[prefix_mod]++;
            }
            else
                freq[prefix_mod] = 1;
        }
        return ans;
    }
};

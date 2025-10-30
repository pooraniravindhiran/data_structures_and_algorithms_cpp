// TC- O(n)
// SC- O(n)

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // sum of subarray from i+1 to j is prefix_sum(j)-prefix(i)
        // condition is (ps(j)-ps(i)) %k == 0 where ps is prefix_sum
        // (q1*k+r1 - q2*k+r2) % k ==0
        // ((q1-q2)*k +r1-r2) % k == 0
        // (r1-r2) % k ==0
        // r1 = r2 because r1 and r2 lie in tange [0, k)
        // ps(j)%k = ps(i)%k

        unordered_map<int, int> prefix_mods;
        prefix_mods[0] = -1;
        int prefix_mod = 0;

        for(int i=0; i<nums.size(); i++){
            prefix_mod = (prefix_mod+nums[i]) % k;

            if(prefix_mods.find(prefix_mod)!=prefix_mods.end()){
                if(i-prefix_mods[prefix_mod]>1)
                    return true;
            }

            prefix_mods[prefix_mod] = i;
        }

        return false;
    }
};


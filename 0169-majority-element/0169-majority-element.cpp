// TC- O(n)
// SC- O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // at every bit, we check the majority bit
        int res = 0;
        for(int i=0; i<32; i++){
            int bitpos = 1<<i;
            int bitcount = 0;
            for(auto num:nums){
                if(num&bitpos)
                    bitcount++;
            }
            if(bitcount>(nums.size()/2))
                res |= bitpos;
        }
        
        return res;
    }
};

// // TC- O(n)
// // SC- O(1)
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int res;
//         int count = 0;
//         for(auto num:nums){
//             if(count==0)
//                 res = num;
//             if(res==num)
//                 count++;
//             else
//                 count--;
//         }
//         return res;
//     }
// };
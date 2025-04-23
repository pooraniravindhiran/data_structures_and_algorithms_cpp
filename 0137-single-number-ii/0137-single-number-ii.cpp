// Tc - O(n)
// SC- O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0; // bits that appeared once
        int twos = 0; // bits that appeared twice

        for(auto num:nums){
            twos |= ones & num; // if num is already present in ones and in num, then it is present twice
            ones ^= num;
            int threes = ones & twos; // bits that appeared three times
            ones &= ~threes; // remove those from 'ones'
            twos &= ~threes; // remove those from 'twos'
        }
        return ones;
    }
};
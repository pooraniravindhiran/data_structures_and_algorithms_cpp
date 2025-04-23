// TC- O(n)
// SC- O(1)

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_all = 0;
        for(auto num:nums)
            xor_all ^= num;

        // xor of all nums = a^b where a and b are the numbers that appear once
        // this xor should have atleast one set bit, i.e atleast one bit ie different btw a and b
        unsigned int diff_bit = static_cast<unsigned int>(xor_all) & (-static_cast<unsigned int>(xor_all));

        int a = 0, b= 0;
        for(auto num:nums){
            if(num & diff_bit)
                a ^= num;
            else
                b ^= num;
        }
        return {a,b};
    }
};
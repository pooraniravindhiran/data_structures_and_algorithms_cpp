// TC- O(1)
// SC- O(1)

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // iterating through every number in this range and doing bitwise-and is bruteforce. Might result in TLE for larger range. 
        // Solution is to find a common prefix for the limits. 
        // This prefix can be found by right shifting both limits until they are equal. And then shift the prefix back.

        int shift = 0;
        while(left!=right){
            left = left>>1;
            right = right>>1;
            shift++;
        }
        return left<<shift;
    }
};
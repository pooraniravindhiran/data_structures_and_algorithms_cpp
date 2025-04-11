class Solution {
public:
    int hammingWeight(int n) {
        int result = 0;
        while(n){
            result += n & 1;
            n = n>>1;
        }
        return result;
    }
};
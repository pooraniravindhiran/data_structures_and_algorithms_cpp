// TC- O(m+n)
// SC- O(m+n)
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // check if there is a common divisor. if so, order of concatenation would not matter.
        if(str1+str2 != str2+str1)
            return "";

        // let's say there is a divisor X, then lets say str1 is n times X and str2 is m times X
        // let's say l is length of X. then, l should be gcd of m and n
        int gcdlen = gcd(str1.size(), str2.size());

        string gcdstr = str1.substr(0, gcdlen);
        return gcdstr;
    }
};
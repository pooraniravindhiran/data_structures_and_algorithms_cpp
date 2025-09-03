// // TC - O(nlogn)
// // SC - O(logn)
// class Solution {
// public:
//     char findTheDifference(string s, string t) {
//         sort(t.begin(), t.end());
//         sort(s.begin(), s.end());
//         for(int i=0; i<s.size(); i++){
//             if(s[i]!=t[i])
//                 return t[i];
//         }
//         return t.back();
//     }
// };

// TC - O(n)
// SC - O(1)
class Solution {
public:
    char findTheDifference(string s, string t) {
        char res = 0; // because 0 when exor'd with anything returns 0
        for(char c:s)
            res ^= c;
        for(char c:t)
            res ^= c;
        return res;
    }
};
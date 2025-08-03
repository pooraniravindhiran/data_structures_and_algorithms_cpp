// TC- O(m+n)
// SC- O(1)

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res;
        res.reserve(word1.size()+word2.size()); // prevents reallocation

        int idx1=0, idx2=0;
        while(idx1<word1.size() or idx2<word2.size()){
            if(idx1<word1.size())
                res.push_back(word1[idx1++]);
            if(idx2<word2.size())
                res.push_back(word2[idx2++]);
        }

        while(idx1<word1.size())
            res.push_back(word1[idx1++]);
        
        while(idx2<word2.size())
            res.push_back(word2[idx2++]);

        return res;
    }
};
// Horizontal scanning
// TC- O(n*m) where n is number of words and m is max num of characters in individual string
// SC- O(1)

// There's also vertical scanning technique, same TC and SC.
// There's also sorting (sort all strings, and just compare first and last str) which gives better TC - O(nlogn+m)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        string lcp = strs[0];

        for(int i=1; i<strs.size(); i++){
            int j=0;
            while(j<min(lcp.size(), strs[i].size()) && lcp[j]==strs[i][j])
                j++;
            lcp = lcp.substr(0, j);
        }
        return lcp;
    }
};
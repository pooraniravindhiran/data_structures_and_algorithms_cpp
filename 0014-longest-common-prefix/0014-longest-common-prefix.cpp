// TC- O(n*m) where n is number of words and m is max num of characters in individual string
// SC- O(1)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        string lcp = strs[0];

        for(int i=1; i<strs.size(); i++){
            int j;
            for(j=0; j<min(lcp.size(), strs[i].size()); ){
                if(lcp[j]==strs[i][j])
                    j++;
                else
                    break;
            }
            lcp = lcp.substr(0, j);
        }
        return lcp;
    }
};
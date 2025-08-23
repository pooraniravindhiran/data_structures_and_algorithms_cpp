class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sptr = 0;
        int tptr = 0;
        while(sptr<s.size() and tptr<t.size()){
            if(s[sptr]==t[tptr])
                sptr++;
            tptr++;
        }
        return sptr ==s.size(); 
    }
};
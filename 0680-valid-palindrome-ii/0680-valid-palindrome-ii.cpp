// TC- O(n)
// SC- O(1)

class Solution {
private:
    bool checkpalindrome(string& s, int i1, int i2){
        for(int i=i1, j=i2; i<j; i++, j--){
            if(s[i]!=s[j])
                return false;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        for(int i=0, j=s.size()-1; i<j; i++, j--){
            if(s[i]!=s[j])
                return checkpalindrome(s, i+1, j) or checkpalindrome(s, i, j-1);
        }
        return true;
    }
};
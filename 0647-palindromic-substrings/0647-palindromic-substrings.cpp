class Solution {
    int countPalindromes(string& ss, int low, int hi){
        int ans = 0;
        while(low>=0 and hi<ss.size()){
            // not a palindrome
            if(ss[low] != ss[hi])
                break;

            low--;
            hi++;
            ans++;
            
        }
        return ans;
    }
public:
    int countSubstrings(string s) {
        int ans =0;
        for(int i=0; i<s.size(); i++){
            ans += countPalindromes(s, i, i);
            ans += countPalindromes(s, i, i+1);
        }
        return ans;
    }
};
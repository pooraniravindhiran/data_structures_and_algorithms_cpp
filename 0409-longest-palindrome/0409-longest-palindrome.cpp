// TC- O(n)
// SC- O(1)

class Solution {
public:
    int longestPalindrome(string s) {
        // count freq of each char
        vector<int> freq(128, 0); 
        for(char c:s)
            freq[c]++;
        
        int len = 0;
        bool hasOdd = false;
        for(auto count:freq){
            len += count/2*2;
            if(count%2!=0)
                hasOdd = true;
        }

        if(hasOdd)
            len +=1;
        return len;

    }
};
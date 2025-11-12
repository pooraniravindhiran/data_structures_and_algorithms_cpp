// TC- O(n)
// SC- O(k)

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int maxlen = 0;
        int currlen = 0;
        int start = 0;
        unordered_map<char, int> freq;
        for(int end=0; end<s.size(); end++){
            freq[s[end]]++;

            while(freq.size()>k){
                // start
                char toremove = s[start];
                start = start + 1;
                
                // remove it from freq
                freq[toremove]--;
                if(freq[toremove]==0)
                    freq.erase(toremove);
            }
            currlen = end-start+1;
            if(currlen>maxlen)
                maxlen = currlen;
        }
        return maxlen;
    }
};
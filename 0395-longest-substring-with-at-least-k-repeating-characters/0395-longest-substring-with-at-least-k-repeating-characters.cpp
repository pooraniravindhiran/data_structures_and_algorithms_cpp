// TC- O(n*26) = O(n)
// SC- O(26) = O(1)

class Solution {
public:
    int longestSubstring(string s, int k) {
        // sliding window approach with just start and end does not work because you need to keep checking char frequencies within that window. optimized soln is rather to check all possible sliding windows for all possible number of distinct chars which makes tracking easier as there are only fixed number of alphabets that s could take

        unordered_map<char, int> freq;
        int maxlen = 0;
        for(int targetdistinctnum=1; targetdistinctnum<=26; targetdistinctnum++){
            // for each iter, consider diff sliding window possibilities- so keep track of start and end. and freq map. and curr num of distinct chars in that window and a var to track number of chars with count >=k
            int start = 0;
            freq.clear();
            int currdistinctnum = 0;
            int countcharsrepeatingk = 0;
            for(int end=0; end<s.size(); end++){
                freq[s[end]]++;
                if(freq[s[end]]==1)
                    currdistinctnum++;
                if(freq[s[end]]==k)
                    countcharsrepeatingk++;
                
                // increment start
                while(currdistinctnum>targetdistinctnum){
                    if(freq[s[start]]==k)
                        countcharsrepeatingk--;
                    freq[s[start]]--;
                    if(freq[s[start]]==0){
                        freq.erase(s[start]);
                        currdistinctnum--;
                    }
                    start++;
                }

                // update max length
                if(currdistinctnum==targetdistinctnum and countcharsrepeatingk==currdistinctnum)
                    maxlen = max(maxlen, end-start+1);
            }
        }
        cout<<maxlen<<endl;
        return maxlen;
    }
};

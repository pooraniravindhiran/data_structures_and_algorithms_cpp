// SC- O(min(n, # of ascii chars))
// TC- O(n)
class Solution {
    unordered_set<char> mem;
    int max_len = 1;
    int curr_len = 1;
public:
    int lengthOfLongestSubstring(string s) {
        // if string is empty
        if (s.length()==0)
            return 0;
        mem.insert(s[0]);

        // iterate through string with i being left and j being right end of the sliding window
        for(int i=0, j=1; i<s.length() && j<s.length(); j++){
            // cout<<i<<" "<<j<<" "<<curr_len<<endl;
            if(mem.find(s[j])==mem.end()){
                mem.insert(s[j]);
                curr_len++;
                if(curr_len>max_len)
                    max_len = curr_len;
            }
            else{
                int pos = s.find(s[j], i);
                // cout<<pos<<endl;
                int temp = i;
                i = pos+1;
                curr_len = j-i+1;
                pos -= 1;
                while(pos>=temp){
                    // cout<<s[pos]<<" ";
                    mem.erase(s[pos]);
                    pos--;
                }
            }
        }
        return max_len;
    }
};
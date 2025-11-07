// TC- O(n)
// SC- O(1)

class Solution {
public:
    string largestPalindromic(string num) {
        vector<int> freq(10, 0);
        // count freq
        for(char c:num)
            freq[c-'0']++;

        string left = "";
        for(int d=9; d>=0; d--){
            int pairs = freq[d]/2;
            if(pairs>0){
                // ignore leading zeroes
                if(d==0 and left=="")
                    continue;
                left.append(pairs, '0'+d); 
                freq[d] -= pairs*2;
            }   
        }
        string mid = "";
        for(int d=9; d>=0; d--){
            if(freq[d]>0){
                mid += '0'+d;
                break;
            }
        }

        if(left=="" and mid=="")
            return "0";
            
        string right = left;
        reverse(right.begin(), right.end());
        return left+mid+right;
    }
};
// TC- O(n)
// SC- O(1)

class Solution {
public:
    int numDecodings(string s) {
        // edge case
        if(s.size()==0)
            return 0;
        
        // base cases
        int two_back = 1;
        int one_back;
        // check for first char
        if(s[0]=='0')
            return 0;
        else
            one_back = 1;
        
        // recurrence relation
        for(int i=1; i<s.size(); i++){
            int current = 0;
            if(s[i]!='0')
                current += one_back;
            if(stoi(s.substr(i-1, 2))>=10 and stoi(s.substr(i-1, 2))<=26)
                current += two_back;
            
            two_back = one_back;
            one_back =current;
        }

        return one_back;
    }
};
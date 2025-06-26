// TC- O(n)
// SC- O(1)

class Solution {
public:
    bool checkValidString(string s) {
        // greedy approach means 
        //        a) we find an impossible scenario, we return false immediately and not wait to process entire string
        //        b) instead of assuming every possible value for '*', we take a lazy approach and just do the range

        // two counter approach where one counter is minimum number of '(' where only '(' is considered and another counter for maximum number of '(' where '*' is also considered as '('
        int low = 0;
        int high = 0;

        for(int i=0; i<s.length(); i++){

            if(s[i]=='('){
                low++;
                high++;
            }

            if(s[i]==')'){
                low--;
                high--;
            }

            if(s[i]=='*'){
                high++;
                low--;
            }

            // means there is no '(' or '*' to the left of currently processed ')'
            if(high<0)
                return false;

            // clamp low to 0
            low = max(low, 0);
        }

        // end condition is that minimum number of '(' should be 0
        if(low!=0)
            return false;
        else
            return true;
    }
};
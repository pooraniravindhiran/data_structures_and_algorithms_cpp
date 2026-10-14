// TC- O(n+l) where n is len of encoded string and l is len of decoded string
// SC- O(n+l)

class Solution {
public:
    string decodeString(string s) {
        stack<int> future_counts;
        stack<string> strs;

        string curr = "";
        int num = 0;

        for(int i=0; i<s.size(); i++){
            char ch = s[i];
            if(isdigit(ch))
                num = (num*10) + (ch-'0');
            else if(ch=='['){
                future_counts.push(num);
                strs.push(curr);
                num = 0;
                curr = "";
            }
            else if(ch==']'){
                string prev = strs.top();
                strs.pop();

                int curr_count = future_counts.top();
                future_counts.pop();

                for(int i=0; i<curr_count; i++)
                    prev += curr;
                curr = prev;
    
            }
            else{
                curr += ch;
            }
        }
        return curr;
    }
};
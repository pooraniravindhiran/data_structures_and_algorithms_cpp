// TC- O(n)
// SC- O(n)

class Solution {
public:
    string decodeString(string s) {
        stack<pair<string, int>> st; // repeat_count, string built so far
        int curr_num = 0;
        string curr_str = "";

        for(int i=0; i<s.size(); i++){
            char ch = s[i];
            if(isdigit(ch))
                curr_num = (curr_num*10)+(ch-'0');

            else if(ch=='['){
                // pause what you're building because new string is there
                st.push({curr_str, curr_num});
                curr_num = 0;
                curr_str = "";
            }
            
            else if(ch==']'){
                auto top = st.top();
                st.pop();
                string temp = "";
                for(int k=0; k<top.second; k++)
                    temp += curr_str;

                temp = top.first + temp;
                curr_str = temp;
            }

            else
                curr_str += ch;
        }

        return curr_str;
    }
};
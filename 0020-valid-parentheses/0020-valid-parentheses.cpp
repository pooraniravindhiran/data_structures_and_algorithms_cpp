// TC- O(n)
// SC- O(n)

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(' or s[i]=='{' or s[i]=='[')
                st.push(s[i]);
            else{
                if(!st.empty() and ((s[i]==']' and st.top()=='[') or (s[i]=='}' and st.top()=='{') or (s[i]==')' and st.top()=='(')))
                    st.pop();
                else
                    return false;
            }
        }
        if(!st.empty())
            return false;
        return true;
    }
};
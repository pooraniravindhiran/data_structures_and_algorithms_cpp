// TC- O(n)
// SC- O(n)

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i=0; i<s.size(); i++){
            char ch = s[i];
            if(ch=='{' or ch=='(' or ch=='[')
                st.push(ch);
            else if(ch=='}' or ch==')' or ch==']'){
                if(st.empty())
                    return false;
                char top = st.top();
                st.pop();
                if((ch==')' and top!='(') or (ch==']' and top!='[') or (ch=='}' and top!='{'))
                    return false;
            }
        }

        if(!st.empty())
            return false;
        
        return true;
    }
};
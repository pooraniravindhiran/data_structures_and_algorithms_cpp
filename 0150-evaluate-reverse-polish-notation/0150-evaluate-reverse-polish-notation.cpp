// TC- O(n)
// SC- O(n)

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0; i<tokens.size(); i++){
            string ch = tokens[i];
            if(ch=="+" or ch=="-" or ch=="*" or ch=="/"){
                int a= st.top();
                st.pop();
                int b= st.top();
                st.pop();
                if(ch=="+")
                    st.push(a+b);
                if(ch=="-")
                    st.push(b-a);
                if(ch=="*")
                    st.push(a*b);
                if(ch=="/")
                    st.push(b/a); 
            }
            else
                st.push(stoi(ch));
        }
        return st.top();
    }
};
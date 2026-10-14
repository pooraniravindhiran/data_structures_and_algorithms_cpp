class Solution {
public:
    int calculate(string s) {
        int num = 0;
        char op ='+';
        stack<int> st;

        for(int i=0; i<s.size()+1; i++){
            char ch = (i==s.size()) ? '+':s[i];

            if(ch==' ')
                continue;
            
            else if(isdigit(ch))
                num = (num*10) + (ch-'0');

            else {
                if(op=='+')
                    st.push(num);
                else if(op=='-')
                    st.push(-num);
                else if(op=='*'){
                    int a = st.top();
                    st.pop();
                    st.push(a*num);
                }
                else{
                    int a = st.top();
                    st.pop();
                    st.push(a/num);
                }
                num = 0;
                op = ch;
            }
        }

        int ans = 0;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};
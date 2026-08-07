// TC- O(n)
// SC- O(n)

class Solution {
public:
    int calculate(string s) {

        long long num = 0;
        char op = '+';
        stack<int> st; // stack because we need all nums. if multiply or divide, we compute immedieately because of precedence

        for(int i = 0; i <= s.size(); i++) {
            char ch = (i < s.size()) ? s[i] : '+';
            if(ch==' ')
                continue;

            else if(isdigit(ch))
                num = (num*10) + ch-'0';
            
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
                op = ch;
                num = 0;

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
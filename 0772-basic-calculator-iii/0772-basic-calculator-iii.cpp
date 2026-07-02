class Solution {
public:
    int i = 0;
    int calculate(string s) {
        return helper(s);
    }

    int helper(string& s){
        stack<int> st;
        int num=0;
        char op = '+';

        while(i<s.size()){
            char ch = s[i];
            if (isdigit(ch))
                num = (num*10)+(ch-'0');

            else if (ch=='('){
                i++;
                num = helper(s);
            }
            if ((!isdigit(ch) && ch!=' ') || (i==s.size()-1)){
                if (op=='+')
                    st.push(num);
                else if (op=='-')
                    st.push(-num);
                else if (op=='*'){
                    int top = st.top(); st.pop();
                    st.push(top*num);
                }
                else if (op=='/'){
                    int top = st.top(); st.pop();
                    st.push(top/num);
                }
                op= ch;
                if(ch==')')
                    break;
                num = 0;
            }
            i++;
        }

        int res = 0;
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        return res;
    }
};
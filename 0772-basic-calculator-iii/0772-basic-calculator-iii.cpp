class Solution {
private:
    int helper(string& s, int& i){
        stack<int> st;
        long long num = 0;
        char op = '+';

        while(i<=s.size()){
            char ch = (i == s.size()) ? '+' : s[i];

            if(isdigit(ch)){
                num = (num*10)+(ch-'0');
                i++;
            }
            
            else if(ch=='('){
                i++;
                num = helper(s, i);
            }

            else {
                if (op=='+')
                    st.push(num);
                else if(op=='-')
                    st.push(-num);
                else if(op=='*'){
                    int a = st.top();
                    st.pop();
                    st.push(a*num);
                }
                else if(op=='/'){
                    int a = st.top();
                    st.pop();
                    st.push(a/num);
                }

                num = 0;

                if(ch==')'){
                    i++;
                    break;
                } 

                op = ch;
                i++;
            }
        }
        int ans = 0;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
public:
    int calculate(string s) {
        int i = 0;
        return helper(s, i);
    }
};
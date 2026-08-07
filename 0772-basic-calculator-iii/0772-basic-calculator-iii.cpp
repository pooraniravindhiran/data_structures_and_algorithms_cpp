// TC- O(n)
// SC- O(n)

class Solution {
public:
    int i=0;
    int calculate(string s) {
        stack<long long> st;
        long long num = 0;
        char sign = '+';
        bool closedbyparen = false;

        while(i<s.size()){
            char ch = s[i];
            if(isdigit(ch))
                num = (num*10) +ch-'0';
            
            else if(ch=='('){
                i++;
                num = calculate(s);
            }

            else {
                if(sign=='+')
                    st.push(num);
                
                else if(sign=='-')
                    st.push(-num);

                else if(sign=='*'){
                    int x = st.top();
                    st.pop();
                    st.push(x * num);
                }
                else if(sign=='/'){
                    int x = st.top();
                    st.pop();
                    st.push(x / num);
                }
                num = 0;
                if(ch==')'){
                    closedbyparen= true;
                    break;
                }
                sign = ch;
            }
            i++;
        }

        if(!closedbyparen){
            // apply last number
            if(sign == '+')
                st.push(num);
            else if(sign == '-')
                st.push(-num);
            else if(sign == '*') {
                int x = st.top();
                st.pop();
                st.push(x * num);
            }
            else if(sign == '/') {
                int x = st.top();
                st.pop();
                st.push(x / num);
            }
        }

        int ans = 0;
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;

    }
};
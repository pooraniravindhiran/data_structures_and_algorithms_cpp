// TC- O(n)
// SC- O(n)

class Solution {
public:
    int calculate(string s) {
        
        stack<long long> st;
        long long num=0;
        long long res=0;
        int sign=1;

        for (int i=0; i<s.size(); i++){
            char ch = s[i];
            if (isdigit(ch))
                num = (num*10)+(ch-'0');
        
            else if (ch=='+'){
                res += sign*num;
                num = 0;
                sign = 1;
            }   

            else if(ch=='-'){
                res += sign*num;
                num = 0;
                sign = -1;
            }   

            else if(ch=='('){
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            }

            else if(ch==')'){
                res += sign*num;
                num=0;
                int prevsign = st.top(); st.pop();
                int prevres = st.top(); st.pop();
                res = prevres + (prevsign*res);
            }

        }
        res += sign*num;
        return (int)res;
    }
};